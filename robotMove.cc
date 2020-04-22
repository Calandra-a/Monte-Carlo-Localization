#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include "mcl.cpp"
#include "particle.cpp"
#include "motion_model.cpp"
#include "robot.cpp"
#include "particleFunctions.cpp"
#include <math.h>

namespace gazebo
{
  class robotMove : public ModelPlugin
  {
    public:double x,y, old_x,old_y;
            robot r;
            map currMap;
            feature measurement;
            pVector<particle> startP;
            

    public:robotMove():ModelPlugin(){
            printf("Start Setup\n"); 
            startP = genParticles(400);
            int range[2] = {90,90};
            measurement.setRange(range);
            //add feature to map if it is a newly measured feature
            if(currMap.checkMeasurement(measurement) == false){
              currMap.setFeature(measurement);
            }
            //plot(startP,r);
            //for (int i =0; i <10; i++){
            printf("Setup Complete!\n");
            printf("Start MCL\n");
            
  
    }
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {

      // Store the pointer to the model
      this->model = _parent;

      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&robotMove::OnUpdate, this));

    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      // Apply a small linear velocity to the model.

      gazebo::math::Pose pose;     
      pose = this->model->GetWorldPose();
      math::Vector3 v(0, 0, 0);
      math::Vector3 v_old(0, 0, 0);

      v_old = pose.pos;
      old_x = v_old.x; // x coordinate
      old_y = v_old.y; // y coordinate    
      int x_p =(int)x+1;
      int y_p =(int)y+1;  
      this->model->GetJoint("left_wheel_hinge") -> SetVelocity(0,1);
      this->model->GetJoint("right_wheel_hinge") -> SetVelocity(0,1);
      if((abs(x-old_x) >=x_p || (abs(y-old_y)>=y_p))){ 
      x = v.x; // x coordinate
      y = v.y; // y coordinate
      r.update(x,y,0);
      int c[2] = {(int)abs(x-old_x),(int)abs(y-old_y)};
      startP = mcl(startP,c,measurement,r,currMap);
    }
  }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(robotMove)
}

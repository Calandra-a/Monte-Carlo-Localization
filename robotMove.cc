#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream> 
#include "mcl.cpp"
#include "particle.cpp"
#include "motion_model.cpp"
//#include "plots/world.cpp"
#include "robot.cpp"
#include "particleFunctions.cpp"
namespace gazebo
{
  class robotMove : public ModelPlugin
  {
    public:double x,y,z;
            robot r;
            map currMap;
            feature measurement;
            pVector<particle> startP;
            int c[2] = {1,0};

    public:robotMove():ModelPlugin(){
            printf("start!\n"); 
            startP = genParticles(400);
            int range[2] = {90,90};
            measurement.setRange(range);
            //add feature to map if it is a newly measured feature
            if(currMap.checkMeasurement(measurement) == false){
              currMap.setFeature(measurement);
            }
            //plot(startP,r);
            //for (int i =0; i <10; i++){
            printf("End constuction!\n");
  
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
      printf("start Update!\n");
      // Apply a small linear velocity to the model.
      this->model->GetJoint("left_wheel_hinge") -> SetVelocity(0,1);
      this->model->GetJoint("right_wheel_hinge") -> SetVelocity(0,1);
      gazebo::math::Pose pose;     
      pose = this->model->GetWorldPose();
      math::Vector3 v(0, 0, 0);
      v = pose.pos;
      x = v.x; // x coordinate
      y = v.y; // y coordinate
      z = v.z; // z coordinate
      std::cout <<"X: " <<x<<" Y: "<<y << " Z: "<<z<<"\n";
      r.update(x,y,z);
      printf("start MCL!\n");
      startP = mcl(startP,c,measurement,r,currMap);
      printf("END MCL!\n");

    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(robotMove)
}

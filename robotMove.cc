#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream>
namespace gazebo
{
  class robotMove : public ModelPlugin
  {
    public:robotMove():ModelPlugin(){
              printf("Hello World!\n");    }
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
      this->model->GetJoint("left_wheel_hinge") -> SetVelocity(0,0.5);
      this->model->GetJoint("right_wheel_hinge") -> SetVelocity(0,0.5);
      //double x,y,z;
      //gazebo::math::Pose pose;     
      //pose = this->model->GetWorldPose();
      //math::Vector3 v(0, 0, 0);
      //v = pose.pos;
      //x = v.x; // x coordinate
      //y = v.y; // y coordinate
      //z = v.z; // z coordinate
      //std::cout <<"X: " <<x<<" Y: "<<y << " Z: "<<z<<"\n";
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(robotMove)
}
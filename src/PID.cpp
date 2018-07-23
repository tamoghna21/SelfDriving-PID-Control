#include <iostream>
#include <math.h>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {is_initialized = false;}

PID::~PID() {}

void PID::Init(double Kp_a, double Ki_a, double Kd_a, double Kp_speed_a, double Ki_speed_a,double Kd_speed_a) {
	Kp = Kp_a;
	Ki = Ki_a;
	Kd = Kd_a;
	
	Kp_speed = Kp_speed_a;
	Ki_speed = Ki_speed_a;
	Kd_speed = Kd_speed_a;
	
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	
	is_initialized = true;
}

void PID::UpdateError(double cte) {
	// DEBUG
    //std::cout << "prev CTE: " << prev_cte << std::endl;
    p_error = cte;
	d_error = cte - prev_cte;
	prev_cte = cte;
	i_error += cte;
	
}

double PID::PIDout(){
    //std::cout << "p_error: " << p_error << "d_error: " << d_error << std::endl;
    //double p_pid = -Kp * p_error;
    //double d_pid = - Kd * d_error;
    //double i_pid = Ki * i_error;
    //std::cout << "p_pid: " << p_pid << "d_pid: " << d_pid << "i_pid: " << i_pid <<std::endl;
	double pid_out = -Kp * p_error - Kd * d_error - Ki * i_error;
	
	return pid_out;
}

double PID::PIDout_speed(){
   //double pid_speed out = -Kp_speed * p_error - Kd_speed * d_error - Ki_speed * i_error ;
	double pid_out_speed = -Kp_speed * p_error - Kd_speed * d_error - Ki_speed * i_error;
   return pid_out_speed;
   }



double PID::TotalError() {
    //double tot_e = -Kp * p_error - Kd * d_error - Ki * i_error;
    //cout << "total_error : " << tot_e << endl;
    double tot_e = p_error * p_error;
	return tot_e;
}


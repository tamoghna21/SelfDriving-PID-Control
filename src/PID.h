#ifndef PID_H
#define PID_H

class PID {
    // Flag, if filter is initialized
	bool is_initialized;
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  double Kp_speed;
  double Ki_speed;
  double Kd_speed;
  
  double prev_cte;
  double int_cte;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp_a, double Ki_a, double Kd_a,double Kp_speed_a, double Ki_speed_a, double Kd_speed_a);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
  const bool initialized() const {
  		return is_initialized;
  }
  
  double PIDout();
  double PIDout_speed();
};

#endif /* PID_H */

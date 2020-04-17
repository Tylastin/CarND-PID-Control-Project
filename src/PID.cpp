#include "PID.h"

/**
 * PID class
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0;
  i_error = 0;
  d_error = 0;

}

void PID::UpdateError(double cte, double dt) {
  /**
   * Update PID errors based on cte and elapsed time. 
   */  
  d_error = (cte - p_error)/dt;
  i_error += cte * dt;
  p_error = cte;

}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return -(Kp * p_error + Ki * i_error + Kd * d_error);
}


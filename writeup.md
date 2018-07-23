# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

[//]: # (Image References)

[video1]: ./video_output/driving_P_control.mov "VideoP"
[video2]: ./video_output/driving_PD_control.mov "VideoPD"
[video3]: ./video_output/driving_PID_full.mov "VideoPID"

---

## Effect each of the P, I, D components had in my implementation.

* Effect of P part of the controller is to compensate for the CTE of the car, but doing so, it easily overshoots the car from its desired trajectory. In the sumulator, that makes the movement of the car too much jittery.

Here's he video for P implementation [link to my video result][video1]

* The D part of the controller compensates for the change in CTE in each step. That helps to damp down the oscillation of the car movement in the simulator.

Here's he video for PD implementation [link to my video result][video2]


* I part of the controller compensates for the steady state error due to any unknown disturbances in the car model etc. In this case, it can take care of steering drift, for example.

Here's he video for PID implementation [link to my video result][video3]

## How the final hyperparameters were chosen.

* I tuned the parameters manually. I first tuned the P parameter so that the car is at least compensating for the CTE. Then the car starts moving jittery way. Then I choose the D parameter to make sure the car moves straight at straight stretches of the road. Then I tuned the I parameter, so that the car is at the center of the lane, especially at the curves, because the car tends to out of the center of the lane due to unknown disturbaces in the car.


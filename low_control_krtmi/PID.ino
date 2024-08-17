
// void controlPID() {
// 	for (int i = 0; i < 4; i++) {
// 		error[i] = set[i] - rpm[i];
// 		if (error[i] < 10 && error[i] > -10) {
// 			zigma_error[i] = 0;
// 		} else
// 			zigma_error[i] += error[i];
// 		delta_error[i] = error[i] - last_error[i];
// 		outputPID[i] = (kp * error[i] + ki[i] * zigma_error[i]
// 				+ kd * delta_error[i]) + pwm[i];
// 		last_error[i] = error[i];

// 		pwm_val[i] = outputPID[i];
// 		if (pwm_val[i] > 255)
// 			pwm_val[i] = 255;
// 		else if (pwm_val[i] < -255)
// 			pwm_val[i] = -255;
// 		pwm[i] = pwm_val[i];
// 	}
// }

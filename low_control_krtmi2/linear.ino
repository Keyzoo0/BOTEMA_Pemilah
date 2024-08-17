

void linearisasi(int index) { 
  
	switch (index) {
	// Linearisasi Motor 1
	case 0:
		if (set[0] > 0) {
			a[index] = 1 * linier_motor1[0];
			b[index] = set[0] * linier_motor1[1];
			c[index] = (set[0] * set[0]) * linier_motor1[2];
			d[index] = (set[0] * set[0] * set[0]) * linier_motor1[3];
			data[0] = (long long) set[0] * set[0] * set[0] * set[0];
			tes[0] = data[0] * linier_motor1[4];
			pwm[0] = a[index] + b[index] + c[index] + d[index] + tes[0];
		} else if (set[0] < 0) {
			a[index] = 1 * linier_motor2[0];
			b[index] = set[0] * linier_motor2[1];
			c[index] = (set[0] * set[0]) * linier_motor2[2];
			d[index] = (set[0] * set[0] * set[0]) * linier_motor2[3];
			data[0] = (long long) set[0] * set[0] * set[0] * set[0];
			tes[0] = data[0] * linier_motor2[4];
			pwm[0] = a[index] + b[index] + c[index] + d[index] + tes[0];
		} else {
			pwm[0] = 0;
		}
		break;

		// Linearisasi Motor 2
	case 1:
		if (set[1] > 0) {
			a[index] = 1 * linier_motor3[0];
			b[index] = set[1] * linier_motor3[1];
			c[index] = (set[1] * set[1]) * linier_motor3[2];
			d[index] = (set[1] * set[1] * set[1]) * linier_motor3[3];
			data[1] = (long long) set[1] * set[1] * set[1] * set[1];
			tes[1] = data[1] * linier_motor3[4];
			pwm[1] = a[index] + b[index] + c[index] + d[index] + tes[1];
		} else if (set[1] < 0) {
			a[index] = 1 * linier_motor4[0];
			b[index] = set[1] * linier_motor4[1];
			c[index] = (set[1] * set[1]) * linier_motor4[2];
			d[index] = (set[1] * set[1] * set[1]) * linier_motor4[3];
			data[1] = (long long) set[1] * set[1] * set[1] * set[1];
			tes[1] = data[1] * linier_motor4[4];
			pwm[1] = a[index] + b[index] + c[index] + d[index] + tes[1];
		} else {
			pwm[1] = 0;
		}
		break;

		// Linearisasi Motor 3
	case 2:
		if (set[2] > 0) {
			a[index] = 1 * linier_motor5[0];
			b[index] = set[2] * linier_motor5[1];
			c[index] = (set[2] * set[2]) * linier_motor5[2];
			d[index] = (set[2] * set[2] * set[2]) * linier_motor5[3];
			data[2] = (long long) set[2] * set[2] * set[2] * set[2];
			tes[2] = data[2] * linier_motor5[4];
			pwm[2] = a[index] + b[index] + c[index] + d[index] + tes[2];
		} else if (set[2] < 0) {
			a[index] = 1 * linier_motor6[0];
			b[index] = set[2] * linier_motor6[1];
			c[index] = (set[2] * set[2]) * linier_motor6[2];
			d[index] = (set[2] * set[2] * set[2]) * linier_motor6[3];
			data[2] = (long long) set[2] * set[2] * set[2] * set[2];
			tes[2] = data[2] * linier_motor6[4];
			pwm[2] = a[index] + b[index] + c[index] + d[index] + tes[2];
		} else {
			pwm[2] = 0;
		}
		break;

		// Linearisasi Motor 4
	case 3:
		if (set[3] > 0) {
			a[index] = 1 * linier_motor7[0];
			b[index] = set[3] * linier_motor7[1];
			c[index] = (set[3] * set[3]) * linier_motor7[2];
			d[index] = (set[3] * set[3] * set[3]) * linier_motor7[3];
			data[3] = (long long) set[3] * set[3] * set[3] * set[3];
			tes[3] = data[3] * linier_motor7[4];
			pwm[3] = a[index] + b[index] + c[index] + d[index] + tes[3];
		} else if (set[3] < 0) {
			a[index] = 1 * linier_motor8[0];
			b[index] = set[3] * linier_motor8[1];
			c[index] = (set[3] * set[3]) * linier_motor8[2];
			d[index] = (set[3] * set[3] * set[3]) * linier_motor8[3];
			data[3] = (long long) set[3] * set[3] * set[3] * set[3];
			tes[3] = data[3] * linier_motor8[4];
			pwm[3] = a[index] + b[index] + c[index] + d[index] + tes[3];
		} else {
			pwm[3] = 0;
		}
		break;
	}

}

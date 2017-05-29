/* Kalman filter */
struct GyroKalman{
	/* These variables represent our state matrix x */
	float x_angle, x_bias;

	/* Our error covariance matrix */
	float P_00, P_01, P_10, P_11;
	
	/*
	* Q is a 2x2 matrix of the covariance. Because we
	* assume the gyro and accelerometer noise to be independent
	* of each other, the covariances on the / diagonal are 0.
	* Covariance Q, the process noise, from the assumption
	* x = F x + B u + w
	* with w having a normal distribution with covariance Q.
	* (covariance = E[ (X - E[X])*(X - E[X])' ]
	* We assume is linear with dt
	*/
	float Q_angle, Q_gyro;

	/*
	* Covariance R, our observation noise (from the accelerometer)
	* Also assumed to be linear with dt
	*/
	float R_angle;
};

typedef union accel_t_gyro_union
{
	struct
	{
	uint8_t x_accel_h;
	uint8_t x_accel_l;
	uint8_t y_accel_h;
	uint8_t y_accel_l;
	uint8_t z_accel_h;
	uint8_t z_accel_l;
	uint8_t t_h;
	uint8_t t_l;
	uint8_t x_gyro_h;
	uint8_t x_gyro_l;
	uint8_t y_gyro_h;
	uint8_t y_gyro_l;
	uint8_t z_gyro_h;
	uint8_t z_gyro_l;
	} reg;

	struct
	{
		int x_accel;
		int y_accel;
		int z_accel;
		int temperature;
		int x_gyro;
		int y_gyro;
		int z_gyro;
	} value;
};

void initGyroKalman(struct GyroKalman *kalman, const float Q_angle, const float Q_gyro, const float R_angle) {
	kalman->Q_angle = Q_angle;
	kalman->Q_gyro = Q_gyro;
	kalman->R_angle = R_angle;
	
	kalman->P_00 = 0;
	kalman->P_01 = 0;
	kalman->P_10 = 0;
	kalman->P_11 = 0;
}

void predict(struct GyroKalman *kalman, float dotAngle, float dt) {
	kalman->x_angle += dt * (dotAngle - kalman->x_bias);
	kalman->P_00 += -1 * dt * (kalman->P_10 + kalman->P_01) + dt*dt * kalman->P_11 + kalman->Q_angle;
	kalman->P_01 += -1 * dt * kalman->P_11;
	kalman->P_10 += -1 * dt * kalman->P_11;
	kalman->P_11 += kalman->Q_gyro;
}

float update(struct GyroKalman *kalman, float angle_m) {
	const float y = angle_m - kalman->x_angle;
	const float S = kalman->P_00 + kalman->R_angle;
	const float K_0 = kalman->P_00 / S;
	const float K_1 = kalman->P_10 / S;
	kalman->x_angle += K_0 * y;
	kalman->x_bias += K_1 * y;
	kalman->P_00 -= K_0 * kalman->P_00;
	kalman->P_01 -= K_0 * kalman->P_01;
	kalman->P_10 -= K_1 * kalman->P_00;
	kalman->P_11 -= K_1 * kalman->P_01;
	return kalman->x_angle;
}

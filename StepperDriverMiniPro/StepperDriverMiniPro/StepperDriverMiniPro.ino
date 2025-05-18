// Motor pins
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;

// 8-step half-stepping sequence for 28BYJ-48
const int seq[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

const int stepDelayMin = 2;   // Fastest speed
const int stepDelayMax = 10;  // Start speed (for ramp)
const int rampSteps = 20;     // Acceleration steps
const int stepsPerRevolution = 256*4;  // 128 full steps × 2 (half-steps)
const float tours = 1;        // Full turns to make

void setup() {
  // Safe pin initialization before enabling outputs
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(5000); // Optional delay for stabilization

  performRotation();  // Do the rotation once at startup

  releaseMotor();
}

void stepMotor(int stepIdx) {
  digitalWrite(IN1, seq[stepIdx][0]);
  digitalWrite(IN2, seq[stepIdx][1]);
  digitalWrite(IN3, seq[stepIdx][2]);
  digitalWrite(IN4, seq[stepIdx][3]);
}

void rotateStepsWithRamp(int steps, bool forward) {
  for (int i = 0; i < steps; i++) {
    int seqIdx = forward ? i % 8 : (7 - (i % 8));
    stepMotor(seqIdx);

    int delayTime = stepDelayMin;
    if (i < rampSteps) {
      delayTime = stepDelayMax - (i * (stepDelayMax - stepDelayMin) / rampSteps);
    }
    delay(round(delayTime));
  }
}

void performRotation() {
  int totalSteps = tours * stepsPerRevolution;
  rotateStepsWithRamp(totalSteps, true);
}

void releaseMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  delay(10000); // Idle loop
}
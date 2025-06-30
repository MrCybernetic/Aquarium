// Motor pins
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;

// 8-step half-stepping sequence for 28BYJ-48
const int halfStepSeq[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}};

// 4-step full-stepping sequence for 28BYJ-48
const int fullStepSeq[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}};

// Mode selection: true = half-step, false = full-step
bool halfStepMode = false; // Set to false for full-step mode

const int stepDelayMin = 5;             // Fastest speed
const int stepDelayMax = 10;            // Start speed (for ramp)
const int rampSteps = 20;               // Acceleration steps
const int stepsPerRevolution = 256 * 4; // 128 full steps × 2 (half-steps)
const float tours = 2;                  // Full turns to make

void setup()
{
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

  performRotation(); // Do the rotation once at startup

  releaseMotor();
}

void stepMotor(int stepIdx)
{
  if (halfStepMode)
  {
    digitalWrite(IN1, halfStepSeq[stepIdx][0]);
    digitalWrite(IN2, halfStepSeq[stepIdx][1]);
    digitalWrite(IN3, halfStepSeq[stepIdx][2]);
    digitalWrite(IN4, halfStepSeq[stepIdx][3]);
  }
  else
  {
    digitalWrite(IN1, fullStepSeq[stepIdx][0]);
    digitalWrite(IN2, fullStepSeq[stepIdx][1]);
    digitalWrite(IN3, fullStepSeq[stepIdx][2]);
    digitalWrite(IN4, fullStepSeq[stepIdx][3]);
  }
}

void rotateStepsWithRamp(int steps, bool forward)
{
  int seqLen = halfStepMode ? 8 : 4;
  for (int i = 0; i < steps; i++)
  {
    int seqIdx = forward ? i % seqLen : (seqLen - 1 - (i % seqLen));
    stepMotor(seqIdx);

    int delayTime = stepDelayMin;
    if (i < rampSteps)
    {
      delayTime = stepDelayMax - (i * (stepDelayMax - stepDelayMin) / rampSteps);
    }
    delay(round(delayTime));
  }
}

void performRotation()
{
  int stepsPerRev = halfStepMode ? 256 * 4 : 256 * 2; // 8 or 4 steps per sequence
  int totalSteps = tours * stepsPerRev;
  rotateStepsWithRamp(totalSteps, true);
}

void releaseMotor()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop()
{
  delay(10000); // Idle loop
}
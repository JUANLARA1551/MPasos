// --- Definición de pines del driver A4988 ---
const int PIN_PASO = 8;
const int PIN_DIRECCION = 9;
const int PIN_MS1 = 10;
const int PIN_MS2 = 3;
const int PIN_MS3 = 2;

void setup() {
  Serial.begin(9600);

  // Inicialización de pines como salida
  for (int pin : {PIN_PASO, PIN_DIRECCION, PIN_MS1, PIN_MS2, PIN_MS3}) {
    pinMode(pin, OUTPUT);
  }

  configurarMicroPasos(4);  // Selección de microstepping a 1/4

  // Mensaje de bienvenida por monitor serie
  Serial.println(">>> Bienvenido al Control de Motor A4988 <<<");
  Serial.println("Opciones de movimiento:");
  Serial.println("1 - 1/4 vuelta en sentido horario");
  Serial.println("2 - 1/2 vuelta en sentido horario");
  Serial.println("3 - 3/4 vuelta en sentido horario");
  Serial.println("4 - 1 vuelta completa en sentido horario");
  Serial.println("5 - 1 vuelta completa en sentido antihorario");
  Serial.println("6 - Un paso (1.8°) en sentido horario");
  Serial.println("7 - Medio paso (0.9°) en sentido horario");
}

void loop() {
  if (Serial.available()) {
    char entrada = Serial.read();
    int cantidadPasos = 0;
    bool giroHorario = true;

    switch (entrada) {

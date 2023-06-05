// Incluir la biblioteca LiquidCrystal
#include <LiquidCrystal.h>

// Definir el número de preguntas en cada examen
const int preguntas = 5;

// Definir los pines para los pulsadores
const int pulsador1 = 8;
const int pulsador2 = 9;

// Inicializar el objeto LiquidCrystal
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Definir las respuestas correctas para cada examen
char respExamen1[preguntas] = {'B', 'C', 'A', 'D', 'B'};
char respExamen2[preguntas] = {'C', 'A', 'B', 'D', 'C'};

// Configuración inicial
void setup() {
  // Inicializar la pantalla LCD
  lcd.begin(16, 2);

  // Configurar los pines de los pulsadores como entradas con resistencia pull-up interna
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);

  // Mostrar mensaje inicial en la pantalla LCD
  lcd.print("Examen PAES");
  delay(2000);
  lcd.clear();
  lcd.print("Presiona un");
  lcd.setCursor(0, 1);
  lcd.print("pulsador");
}

// Bucle principal
void loop() {
  // Verificar si se presionó el pulsador 1
  if (digitalRead(pulsador1) == LOW) {
    // Seleccionar el examen 1
    seleccionarExamen(respExamen1, "Examen 1");
  }

  // Verificar si se presionó el pulsador 2
  if (digitalRead(pulsador2) == LOW) {
    // Seleccionar el examen 2
    seleccionarExamen(respExamen2, "Examen 2");
  }
}

// Función para seleccionar un examen y calificarlo
void seleccionarExamen(char respuestas[], const char* nombreExamen) {
  // Limpiar la pantalla LCD y mostrar el nombre del examen
  lcd.clear();
  lcd.print("Calificando");
  lcd.setCursor(0, 1);
  lcd.print(nombreExamen);
  delay(2000);

  // Calificar el examen y obtener la nota
  int nota = calificarExamen(respuestas);

  // Mostrar la nota en la pantalla LCD
  mostrarNota(nota);
  delay(2000);
  lcd.clear();
  
  // Esperar siguiente pulsación
  lcd.print("Presiona un");
  lcd.setCursor(0, 1);
  lcd.print("pulsador");
}

// Función para calificar un examen y retornar la nota
int calificarExamen(char respuestasExamen[]) {
  int nota = 0;

  // Arreglo para almacenar las respuestas del alumno
  char respuestasAlumno[preguntas];

  // Calificar cada pregunta del examen
  for (int i = 0; i < preguntas; i++) {
    // Generar una respuesta aleatoria del alumno
    respuestasAlumno[i] = random('A', 'D' + 1);

    // Mostrar la opción seleccionada por el alumno
    lcd.clear();
    lcd.print("Opc alumno: ");
    lcd.print(respuestasAlumno[i]);
    delay(2000);

    // Mostrar la opción correcta
    lcd.clear();
    lcd.print("Opc correcta: ");
    lcd.print(respuestasExamen[i]);
    delay(2000);

    // Mostrar si la respuesta del alumno es correcta o incorrecta
    lcd.clear();
    lcd.print("Respuesta");
    lcd.setCursor(0, 1);
    if (respuestasAlumno[i] == respuestasExamen[i]) {
      lcd.print("correcta +2");
    } else {
      lcd.print("incorrecta");
    }
    delay(2000);
  }

  // Calcular la nota sumando 2 puntos por cada respuesta correcta
  for (int i = 0; i < preguntas; i++) {
    if (respuestasAlumno[i] == respuestasExamen[i]) {
      nota += 2;
    }
  }

  // Retornar la nota obtenida
  return nota;
}

// Función para mostrar la nota en la pantalla LCD
void mostrarNota(int nota) {
  lcd.clear();
  lcd.print("Nota: ");
  lcd.print(nota);
}

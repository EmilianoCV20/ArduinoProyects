#include "fis_header.h"
#include <DHT.h>

#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Número de entradas al sistema de inferencia difusa
const int fis_gcI = 3;

// Número de salidas del sistema de inferencia difusa
const int fis_gcO = 1;

// Número de reglas del sistema de inferencia difusa
//const int fis_gcR = 27; MAXIMO DE REGLAS ACEPTADAS
const int fis_gcR = 60;

FIS_TYPE g_fisInput[fis_gcI];
FIS_TYPE g_fisOutput[fis_gcO];

// Configuración inicial
void setup() {
  Serial.begin(9600);
  dht.begin();

  // Inicializar los pines de entrada
  pinMode(A0, INPUT); // Humedad

  // Inicializar los pines de salida
  pinMode(3, OUTPUT); // Duración
}

// Bucle principal
void loop() {
  // Leer entradas
  // Hora fija 
  g_fisInput[0] = 5.3; // Valor fijo

  // Leer Humedad
  int valorHumedad = map(analogRead(A0), 0, 1023, 100, 0);
  g_fisInput[1] = valorHumedad;
  //g_fisInput[1] = 20;

  // Leer Temperatura usando el sensor DHT11
  g_fisInput[2] = dht.readTemperature();
  //g_fisInput[2] = 14.9;

  // Inicializar la salida en cero
  g_fisOutput[0] = 0;

  // Evaluar el sistema difuso 
  fis_evaluate();

  // Imprimir datos
  Serial.print("T: ");
  Serial.println("5:30");

  //int valorHumedad = map(analogRead(A0), 0, 1023, 100, 0);
  Serial.print("H: ");
  Serial.println(g_fisInput[1]);

  Serial.print("Temp: ");
  Serial.println(g_fisInput[2]);

  Serial.print("R: ");
  Serial.println(g_fisOutput[0]);

  delay(1000);
}


//***********************************************************************
// Support functions for Fuzzy Inference System                          
//***********************************************************************
// Triangular Member Function
FIS_TYPE fis_trimf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE a = p[0], b = p[1], c = p[2];
    FIS_TYPE t1 = (x - a) / (b - a);
    FIS_TYPE t2 = (c - x) / (c - b);
    if ((a == b) && (b == c)) return (FIS_TYPE) (x == a);
    if (a == b) return (FIS_TYPE) (t2*(b <= x)*(x <= c));
    if (b == c) return (FIS_TYPE) (t1*(a <= x)*(x <= b));
    t1 = min(t1, t2);
    return (FIS_TYPE) max(t1, 0);
}

// Trapezoidal Member Function
FIS_TYPE fis_trapmf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE a = p[0], b = p[1], c = p[2], d = p[3];
    FIS_TYPE t1 = ((x <= c) ? 1 : ((d < x) ? 0 : ((c != d) ? ((d - x) / (d - c)) : 0)));
    FIS_TYPE t2 = ((b <= x) ? 1 : ((x < a) ? 0 : ((a != b) ? ((x - a) / (b - a)) : 0)));
    return (FIS_TYPE) min(t1, t2);
}

FIS_TYPE fis_min(FIS_TYPE a, FIS_TYPE b)
{
    return min(a, b);
}

FIS_TYPE fis_max(FIS_TYPE a, FIS_TYPE b)
{
    return max(a, b);
}

FIS_TYPE fis_array_operation(FIS_TYPE *array, int size, _FIS_ARR_OP pfnOp)
{
    int i;
    FIS_TYPE ret = 0;

    if (size == 0) return ret;
    if (size == 1) return array[0];

    ret = array[0];
    for (i = 1; i < size; i++)
    {
        ret = (*pfnOp)(ret, array[i]);
    }

    return ret;
}


//***********************************************************************
// Data for Fuzzy Inference System                                       
//***********************************************************************
// Pointers to the implementations of member functions
_FIS_MF fis_gMF[] =
{
    fis_trimf, fis_trapmf
};

// Count of member function for each Input
int fis_gIMFCount[] = { 2, 5, 6 };

// Count of member function for each Output 
int fis_gOMFCount[] = { 4 };

// Coefficients for the Input Member Functions
FIS_TYPE fis_gMFI0Coeff1[] = { 5.25, 5.3, 5.35 };
FIS_TYPE fis_gMFI0Coeff2[] = { 21.25, 21.3, 21.35 };
FIS_TYPE* fis_gMFI0Coeff[] = { fis_gMFI0Coeff1, fis_gMFI0Coeff2 };
FIS_TYPE fis_gMFI1Coeff1[] = { 0, 0, 10, 30 };
FIS_TYPE fis_gMFI1Coeff2[] = { 10, 30, 40, 50 };
FIS_TYPE fis_gMFI1Coeff3[] = { 40, 50, 60, 70 };
FIS_TYPE fis_gMFI1Coeff4[] = { 60, 70, 80, 90 };
FIS_TYPE fis_gMFI1Coeff5[] = { 80, 90, 100, 100 };
FIS_TYPE* fis_gMFI1Coeff[] = { fis_gMFI1Coeff1, fis_gMFI1Coeff2, fis_gMFI1Coeff3, fis_gMFI1Coeff4, fis_gMFI1Coeff5 };
FIS_TYPE fis_gMFI2Coeff1[] = { 8, 8, 10, 12 };
FIS_TYPE fis_gMFI2Coeff2[] = { 10.0474040632054, 12.0474040632054, 14.0474040632054, 15.0474040632054 };
FIS_TYPE fis_gMFI2Coeff3[] = { 14, 15, 17, 18 };
FIS_TYPE fis_gMFI2Coeff4[] = { 17, 18, 20, 21 };
FIS_TYPE fis_gMFI2Coeff5[] = { 20, 21, 26, 27 };
FIS_TYPE fis_gMFI2Coeff6[] = { 26, 27, 50, 50 };
FIS_TYPE* fis_gMFI2Coeff[] = { fis_gMFI2Coeff1, fis_gMFI2Coeff2, fis_gMFI2Coeff3, fis_gMFI2Coeff4, fis_gMFI2Coeff5, fis_gMFI2Coeff6 };
FIS_TYPE** fis_gMFICoeff[] = { fis_gMFI0Coeff, fis_gMFI1Coeff, fis_gMFI2Coeff };

// Coefficients for the Output Member Functions
FIS_TYPE fis_gMFO0Coeff1[] = { 0, 0, 3, 3 };
FIS_TYPE fis_gMFO0Coeff2[] = { 3, 3, 6, 6 };
FIS_TYPE fis_gMFO0Coeff3[] = { 6, 6, 10, 10 };
FIS_TYPE fis_gMFO0Coeff4[] = { 0, 0, 0, 0 };
FIS_TYPE* fis_gMFO0Coeff[] = { fis_gMFO0Coeff1, fis_gMFO0Coeff2, fis_gMFO0Coeff3, fis_gMFO0Coeff4 };
FIS_TYPE** fis_gMFOCoeff[] = { fis_gMFO0Coeff };

// Input membership function set
int fis_gMFI0[] = { 0, 0 };
int fis_gMFI1[] = { 1, 1, 1, 1, 1 };
int fis_gMFI2[] = { 1, 1, 1, 1, 1, 1 };
int* fis_gMFI[] = { fis_gMFI0, fis_gMFI1, fis_gMFI2};

// Output membership function set
int fis_gMFO0[] = { 1, 1, 1, 1 };
int* fis_gMFO[] = { fis_gMFO0};


// Rule Weights
FIS_TYPE fis_gRWeight[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Type
int fis_gRType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


// Rule Inputs
int fis_gRI0[] = { 1, 1, 1 };
int fis_gRI1[] = { 2, 1, 1 };
int fis_gRI2[] = { 1, 2, 1 };
int fis_gRI3[] = { 2, 2, 1 };
int fis_gRI4[] = { 1, 3, 1 };
int fis_gRI5[] = { 2, 3, 1 };
int fis_gRI6[] = { 1, 4, 1 };
int fis_gRI7[] = { 2, 4, 1 };
int fis_gRI8[] = { 1, 5, 1 };
int fis_gRI9[] = { 2, 5, 1 };
int fis_gRI10[] = { 1, 1, 2 };
int fis_gRI11[] = { 2, 1, 2 };
int fis_gRI12[] = { 1, 2, 2 };
int fis_gRI13[] = { 2, 2, 2 };
int fis_gRI14[] = { 1, 3, 2 };
int fis_gRI15[] = { 2, 3, 2 };
int fis_gRI16[] = { 1, 4, 2 };
int fis_gRI17[] = { 2, 4, 2 };
int fis_gRI18[] = { 1, 5, 2 };
int fis_gRI19[] = { 2, 5, 2 };
int fis_gRI20[] = { 1, 1, 3 };
int fis_gRI21[] = { 2, 1, 3 };
int fis_gRI22[] = { 1, 2, 3 };
int fis_gRI23[] = { 2, 2, 3 };
int fis_gRI24[] = { 1, 3, 3 };
int fis_gRI25[] = { 2, 3, 3 };
int fis_gRI26[] = { 1, 4, 3 };
int fis_gRI27[] = { 2, 4, 3 };
int fis_gRI28[] = { 1, 5, 3 };
int fis_gRI29[] = { 2, 5, 3 };
int fis_gRI30[] = { 1, 1, 4 };
int fis_gRI31[] = { 2, 1, 4 };
int fis_gRI32[] = { 1, 2, 4 };
int fis_gRI33[] = { 2, 2, 4 };
int fis_gRI34[] = { 1, 3, 4 };
int fis_gRI35[] = { 2, 3, 4 };
int fis_gRI36[] = { 1, 4, 4 };
int fis_gRI37[] = { 2, 4, 4 };
int fis_gRI38[] = { 1, 5, 4 };
int fis_gRI39[] = { 2, 5, 4 };
int fis_gRI40[] = { 1, 1, 5 };
int fis_gRI41[] = { 2, 1, 5 };
int fis_gRI42[] = { 1, 2, 5 };
int fis_gRI43[] = { 2, 2, 5 };
int fis_gRI44[] = { 1, 3, 5 };
int fis_gRI45[] = { 2, 3, 5 };
int fis_gRI46[] = { 1, 4, 5 };
int fis_gRI47[] = { 2, 4, 5 };
int fis_gRI48[] = { 1, 5, 5 };
int fis_gRI49[] = { 2, 5, 5 };
int fis_gRI50[] = { 1, 1, 6 };
int fis_gRI51[] = { 2, 1, 6 };
int fis_gRI52[] = { 1, 2, 6 };
int fis_gRI53[] = { 2, 2, 6 };
int fis_gRI54[] = { 1, 3, 6 };
int fis_gRI55[] = { 2, 3, 6 };
int fis_gRI56[] = { 1, 4, 6 };
int fis_gRI57[] = { 2, 4, 6 };
int fis_gRI58[] = { 1, 5, 6 };
int fis_gRI59[] = { 2, 5, 6 };
int* fis_gRI[] = { fis_gRI0, fis_gRI1, fis_gRI2, fis_gRI3, fis_gRI4, fis_gRI5, fis_gRI6, fis_gRI7, fis_gRI8, fis_gRI9, fis_gRI10, fis_gRI11, fis_gRI12, fis_gRI13, fis_gRI14, fis_gRI15, fis_gRI16, fis_gRI17, fis_gRI18, fis_gRI19, fis_gRI20, fis_gRI21, fis_gRI22, fis_gRI23, fis_gRI24, fis_gRI25, fis_gRI26, fis_gRI27, fis_gRI28, fis_gRI29, fis_gRI30, fis_gRI31, fis_gRI32, fis_gRI33, fis_gRI34, fis_gRI35, fis_gRI36, fis_gRI37, fis_gRI38, fis_gRI39, fis_gRI40, fis_gRI41, fis_gRI42, fis_gRI43, fis_gRI44, fis_gRI45, fis_gRI46, fis_gRI47, fis_gRI48, fis_gRI49, fis_gRI50, fis_gRI51, fis_gRI52, fis_gRI53, fis_gRI54, fis_gRI55, fis_gRI56, fis_gRI57, fis_gRI58, fis_gRI59 };

// Rule Outputs
int fis_gRO0[] = { 1 };
int fis_gRO1[] = { 1 };
int fis_gRO2[] = { 1 };
int fis_gRO3[] = { 1 };
int fis_gRO4[] = { 1 };
int fis_gRO5[] = { 1 };
int fis_gRO6[] = { 4 };
int fis_gRO7[] = { 4 };
int fis_gRO8[] = { 4 };
int fis_gRO9[] = { 4 };
int fis_gRO10[] = { 1 };
int fis_gRO11[] = { 1 };
int fis_gRO12[] = { 1 };
int fis_gRO13[] = { 1 };
int fis_gRO14[] = { 1 };
int fis_gRO15[] = { 1 };
int fis_gRO16[] = { 1 };
int fis_gRO17[] = { 1 };
int fis_gRO18[] = { 4 };
int fis_gRO19[] = { 4 };
int fis_gRO20[] = { 2 };
int fis_gRO21[] = { 2 };
int fis_gRO22[] = { 2 };
int fis_gRO23[] = { 2 };
int fis_gRO24[] = { 2 };
int fis_gRO25[] = { 2 };
int fis_gRO26[] = { 1 };
int fis_gRO27[] = { 1 };
int fis_gRO28[] = { 4 };
int fis_gRO29[] = { 4 };
int fis_gRO30[] = { 2 };
int fis_gRO31[] = { 2 };
int fis_gRO32[] = { 2 };
int fis_gRO33[] = { 2 };
int fis_gRO34[] = { 2 };
int fis_gRO35[] = { 2 };
int fis_gRO36[] = { 1 };
int fis_gRO37[] = { 1 };
int fis_gRO38[] = { 4 };
int fis_gRO39[] = { 4 };
int fis_gRO40[] = { 3 };
int fis_gRO41[] = { 3 };
int fis_gRO42[] = { 3 };
int fis_gRO43[] = { 3 };
int fis_gRO44[] = { 2 };
int fis_gRO45[] = { 2 };
int fis_gRO46[] = { 1 };
int fis_gRO47[] = { 1 };
int fis_gRO48[] = { 4 };
int fis_gRO49[] = { 4 };
int fis_gRO50[] = { 3 };
int fis_gRO51[] = { 3 };
int fis_gRO52[] = { 3 };
int fis_gRO53[] = { 3 };
int fis_gRO54[] = { 3 };
int fis_gRO55[] = { 3 };
int fis_gRO56[] = { 2 };
int fis_gRO57[] = { 2 };
int fis_gRO58[] = { 1 };
int fis_gRO59[] = { 1 };
int* fis_gRO[] = { fis_gRO0, fis_gRO1, fis_gRO2, fis_gRO3, fis_gRO4, fis_gRO5, fis_gRO6, fis_gRO7, fis_gRO8, fis_gRO9, fis_gRO10, fis_gRO11, fis_gRO12, fis_gRO13, fis_gRO14, fis_gRO15, fis_gRO16, fis_gRO17, fis_gRO18, fis_gRO19, fis_gRO20, fis_gRO21, fis_gRO22, fis_gRO23, fis_gRO24, fis_gRO25, fis_gRO26, fis_gRO27, fis_gRO28, fis_gRO29, fis_gRO30, fis_gRO31, fis_gRO32, fis_gRO33, fis_gRO34, fis_gRO35, fis_gRO36, fis_gRO37, fis_gRO38, fis_gRO39, fis_gRO40, fis_gRO41, fis_gRO42, fis_gRO43, fis_gRO44, fis_gRO45, fis_gRO46, fis_gRO47, fis_gRO48, fis_gRO49, fis_gRO50, fis_gRO51, fis_gRO52, fis_gRO53, fis_gRO54, fis_gRO55, fis_gRO56, fis_gRO57, fis_gRO58, fis_gRO59 };

// Input range Min
FIS_TYPE fis_gIMin[] = { 0, 0, 8 };

// Input range Max
FIS_TYPE fis_gIMax[] = { 24, 100, 50 };

// Output range Min
FIS_TYPE fis_gOMin[] = { 0 };

// Output range Max
FIS_TYPE fis_gOMax[] = { 10 };

//***********************************************************************
// Data dependent support functions for Fuzzy Inference System           
//***********************************************************************
FIS_TYPE fis_MF_out(FIS_TYPE** fuzzyRuleSet, FIS_TYPE x, int o)
{
    FIS_TYPE mfOut;
    int r;

    for (r = 0; r < fis_gcR; ++r)
    {
        int index = fis_gRO[r][o];
        if (index > 0)
        {
            index = index - 1;
            mfOut = (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else if (index < 0)
        {
            index = -index - 1;
            mfOut = 1 - (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else
        {
            mfOut = 0;
        }

        fuzzyRuleSet[0][r] = fis_min(mfOut, fuzzyRuleSet[1][r]);
    }
    return fis_array_operation(fuzzyRuleSet[0], fis_gcR, fis_max);
}

FIS_TYPE fis_defuzz_centroid(FIS_TYPE** fuzzyRuleSet, int o)
{
    FIS_TYPE step = (fis_gOMax[o] - fis_gOMin[o]) / (FIS_RESOLUSION - 1);
    FIS_TYPE area = 0;
    FIS_TYPE momentum = 0;
    FIS_TYPE dist, slice;
    int i;

    // calculate the area under the curve formed by the MF outputs
    for (i = 0; i < FIS_RESOLUSION; ++i){
        dist = fis_gOMin[o] + (step * i);
        slice = step * fis_MF_out(fuzzyRuleSet, dist, o);
        area += slice;
        momentum += slice*dist;
    }

    return ((area == 0) ? ((fis_gOMax[o] + fis_gOMin[o]) / 2) : (momentum / area));
}

//***********************************************************************
// Fuzzy Inference System                                                
//***********************************************************************
void fis_evaluate()
{
    FIS_TYPE fuzzyInput0[] = { 0, 0 };
    FIS_TYPE fuzzyInput1[] = { 0, 0, 0, 0, 0 };
    FIS_TYPE fuzzyInput2[] = { 0, 0, 0, 0, 0, 0 };
    FIS_TYPE* fuzzyInput[fis_gcI] = { fuzzyInput0, fuzzyInput1, fuzzyInput2, };
    FIS_TYPE fuzzyOutput0[] = { 0, 0, 0, 0 };
    FIS_TYPE* fuzzyOutput[fis_gcO] = { fuzzyOutput0, };
    FIS_TYPE fuzzyRules[fis_gcR] = { 0 };
    FIS_TYPE fuzzyFires[fis_gcR] = { 0 };
    FIS_TYPE* fuzzyRuleSet[] = { fuzzyRules, fuzzyFires };
    FIS_TYPE sW = 0;

    // Transforming input to fuzzy Input
    int i, j, r, o;
    for (i = 0; i < fis_gcI; ++i)
    {
        for (j = 0; j < fis_gIMFCount[i]; ++j)
        {
            fuzzyInput[i][j] =
                (fis_gMF[fis_gMFI[i][j]])(g_fisInput[i], fis_gMFICoeff[i][j]);
        }
    }

    int index = 0;
    for (r = 0; r < fis_gcR; ++r)
    {
        if (fis_gRType[r] == 1)
        {
            fuzzyFires[r] = FIS_MAX;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1);
            }
        }
        else
        {
            fuzzyFires[r] = FIS_MIN;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 0);
            }
        }

        fuzzyFires[r] = fis_gRWeight[r] * fuzzyFires[r];
        sW += fuzzyFires[r];
    }

    if (sW == 0)
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = ((fis_gOMax[o] + fis_gOMin[o]) / 2);
        }
    }
    else
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = fis_defuzz_centroid(fuzzyRuleSet, o);
        }
    }
}

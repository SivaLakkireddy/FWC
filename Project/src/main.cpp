#include<Arduino.h>
#include<WiFi.h>
#include<AsyncTCP.h>
#include<ESPAsyncWebServer.h>
#include<math.h>
#include"lib.h"

AsyncWebServer server(80);

const char* ssid = "Siva";
const char* password = "siva1234";

const char* input_parameter20 = "input20";
const char* input_parameter21 = "input21";
const char* input_parameter00 = "input00";
const char* input_parameter01 = "input01";
const char* input_parameter10 = "input10";
const char* input_parameter11 = "input11";

const char* matrix1[2]={input_parameter20,input_parameter21};
const char* matrix2[4]={input_parameter00,input_parameter01,input_parameter10,input_parameter11};

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>COORDINATES OF A</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 2.0rem; color: blue;}
  </style> 
  </head><body>
  <h2>TO FIND COORDINATES OF A</h2> 
  <p>Enter the values of points e2,q1
  <form action="/get">
    Enter the values of e2: <input type="number" name="input20"><br><input type="number" name="input21"><br>
    Enter the values of q1: <input type="number" name="input00"><br><input type="number" name="input01"><br><input type="number" name="input10"><br><input type="number" name="input11"><br>
    <input type="submit" value="Submit">
    
  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connecting...");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
        double a = 8, k = 3.5, theta = M_PI * 1/4, **r, b;
	double cosine = cos(theta), sine = sin(theta);
	double **e2, **q1, **q2, **q, **A;

	e2 = load_ser(request,matrix1);
	q1 = load_serv(request,matrix2);

        q2 = createMat(2,1);
	q2[0][0] = -pow(a,2)/k;
	q2[1][0] = -k;

	q = matmul(q1,q2,2,2,1);
        r = matmul(transpose(e2,2,1),q,1,2,1);
	b = 1/(2*(1-(a*cosine)/k))*r[0][0];
	A = createMat(2,1);
	A[0][0] = b*cosine;
	A[1][0] = b*sine;

	request->send(200, "text/html", "The Coordinates of A are " + String(A[0][0]) + " " + String(A[1][0])+" <br><a href=\"/\">Return to Home Page</a>");}

);   

  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  
}

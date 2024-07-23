int arr1[5] = {1,2,3,4,5};
int arr2[10] = {1,2,3,4,5,6,7,8,9,10};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("aaa");
  
  Serial.println( String(arr2[0]) );
  Serial.println( String(arr2[9]) );

  for(int i=0; i<9; i+=1){
    Serial.println( arr2[i] );
  }
  delay(100);
}

int plus_3(int a){
  return a + 3;
}

char a(){
  return 'a';
}

void print(int a){
  if (a%2==0)  Serial.println( String(a/2) );
  else  Serial.println( String(a+1) );
}

char received(){
  if( Serial.available() ) return Serial.read();
  else return '?';
}












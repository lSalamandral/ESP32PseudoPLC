const String Pagina= R"***(

<!DOCTYPE html>
<html lang="en">
<head>
   
    <style>
      ::-webkit-scrollbar {
  width: 10px;
}


::-webkit-scrollbar-track {
  background: rgb(186, 190, 190); 
}
 

::-webkit-scrollbar-thumb {
  background: #888; 
}


::-webkit-scrollbar-thumb:hover {
  background: #555; 
}
h1{
  font-size: medium;
  color: rgb(184, 221, 185);
}
       body{
        background-color: rgb(186, 190, 190);
        background-image: url('https://wallpapercave.com/wp/wp6451491.jpg');
        background-position: bottom;
        background-size: cover ;
        background-attachment: fixed;
        background-repeat: no-repeat;
        
        position: relative;
       } 
       .sonker{
        font-family: verdana;
        font-size:4vw; 
        
       }
       .menu{
           background-color: rgb(186, 190, 190); 
           padding: 12px 20px;
           font-family: verdana;
           box-sizing: border-box;
           border-radius: 10px;
           font-size: 2.5vw; 
           border: 2px solid #ccc;
           cursor: pointer;
          
       }
        .titulo{
          
            font-family: verdana;
            font-size: 3rem;
            float: center ;
            width: auto;
            border-radius: 15px;
            text-align: center;
            color: rgb(37, 33, 33);
background: radial-gradient(circle, rgb(189, 186, 186) 6%, rgba(128, 160, 134, 0.925) 87%);
        }
.boton{
    background-image: linear-gradient(to right, rgb(117, 135, 146) 0%, rgb(81, 108, 121) 51%, rgb(49, 71, 85) 100%);
    border-radius: 5px;
    height: max-content;
    color: antiquewhite;
    font-size: 1.8vw;
    margin: 4px 2px;
    padding: 8% 15%;
    font-family: Verdana,Tahoma, sans-serif;
    cursor: pointer;
    

}
.boton:hover {
    transition: 500ms;
    border-radius: 50px;
}

.derecha{
  
    width:18%;
    min-height: auto;
  padding: 1%;
  border-left: 2px solid rgb(59, 92, 82);
  margin: 3px;
  float:right;
  
  
  
  
}
.izquierda{
 width: 74%;
  padding: 1%;
  height: 40vw;
  float: left;
  overflow-y:auto;
  
    
}

    </style>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32</title>
</head>
<body>
    
    
    <div class="titulo">Carga de datos para ESP32</div>
    <div class="izquierda" id="cuadro"></div>

 <div class="derecha">
    <div><button class="boton Agregar" id="agregar" onclick="Agregar()">Agregar</button></div>
    <div><button class="boton Borrar"onclick="Borrar()">Borrar</button></div>
    <div><button class="boton P" onclick="Programar()">Programar</button></div>
    <div><button class="boton Ejecutar" onclick="Ejecutar()">Ejecutar</button></div>
    <div><button class="boton Detener" onclick="Pausar()">Pausar</button></div>
    <div><button class="boton Detener" onclick="Detener()">Detener</button></div>
    <div><h1>Tareas cargadas:<span id="Inst">0</span></h1></div>
</div>


 </button>   
</body>
</html>
<script >console.log("correcto");

var aux = 0;
var state = 0;
var state2 = 0;
var lista;
var op;
var txt;
var select;
var label;
var auxV = 0;
var auxC = 0;
var extra;
var extra2;
var type_V=0,Type_L=0;

function Agregar() {
  console.log(state);

  if (state == 0 || state >= 3) {
    aux++;
    extra2 = 0;
    auxV = 0;
    auxC = 0;
    state = 0;
    type_V=0;
    Type_L=0;
    instruccion = document.createElement("p");
    instruccion.className = "sonker";
    instruccion.id = "sonker" + aux;
    lista = document.createElement("form");
    lista.name = "IF";
    lista.className= "menu";
    lista.id = "form" + aux;

    label = document.createElement("label" + aux);
    txt = document.createTextNode("IF ");
    label.appendChild(txt);

    lista.appendChild(label);
    Vari(state);

    instruccion.append(lista);

    cuadro.appendChild(instruccion);
  }
}

function Vari(a) {
 
    select = document.createElement("select");
    select.id = auxV + "selectVar" + aux;

    op = document.createElement("option");
    op.className = "menu";
    op.value = "Null";
    txt = document.createTextNode("---");
    op.appendChild(txt);
    select.appendChild(op);
    if(Type_L==0||Type_L==1){
    op = document.createElement("option");
    op.className = "menu";
    op.value = "D1";
    txt = document.createTextNode("1D");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "D2";
    txt = document.createTextNode("2D");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "D3";
    txt = document.createTextNode("3D");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "D4";
    txt = document.createTextNode("4D");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
      op.className = "menu";
      op.value = "1S";
      txt = document.createTextNode("1S");
      op.appendChild(txt);
      select.appendChild(op);
      label.appendChild(select);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "2S";
      txt = document.createTextNode("2S");
      op.appendChild(txt);
      select.appendChild(op);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "3S";
      txt = document.createTextNode("3S");
      op.appendChild(txt);
      select.appendChild(op);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "4S";
      txt = document.createTextNode("4S");
      op.appendChild(txt);
      select.appendChild(op);
    }
    if(Type_L==0||Type_L==2){
    op = document.createElement("option");
    op.className = "menu";
    op.value = "A1";
    txt = document.createTextNode("1A");
    op.appendChild(txt);
    select.appendChild(op);
    label.appendChild(select);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "A2";
    txt = document.createTextNode("2A");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "A3";
    txt = document.createTextNode("3A");
    op.appendChild(txt);
    select.appendChild(op);
    op = document.createElement("option");
    op.className = "menu";
    op.value = "A4";
    txt = document.createTextNode("4A");
    op.appendChild(txt);
    select.appendChild(op);    
    }
    if (state < 2) {
      lista.appendChild(select);
    }
    if (state >= 2) {
      lista.insertBefore(select, document.getElementById("label2" + aux));
    }

    select.addEventListener("change", Type_V_swich);
    auxV++;
    state++;
  
}

function logi() {
  
  if (state == 2 && state <= 3) {
    final();
    console.log(state);
  }
  if(state==1){
    
  
    if(document.getElementById(auxC-1 + "Condi" + aux)!=null){
      document.getElementById("form" + aux).removeChild(document.getElementById(auxC-1 + "Condi" + aux));
     
      console.log("auxC es"+auxC);
          
      
    if(document.getElementById(auxC-1 + "NOT" + aux)){
      document.getElementById("form" + aux).removeChild(document.getElementById(aux-1 + "NOT" + aux)); 
    }
    auxC--;
    }
  }
  if(state>1){
    document.getElementById(auxV-1 + "selectVar" + aux).removeEventListener("change",Type_V_swich);
    }
  
  
  lista = document.getElementById("form" + aux);
  lista.className= "menu";
  
  
  if(type_V==1){
  select = document.createElement("select");
  select.id = auxC + "NOT" + aux;
  op = document.createElement("option");
  op.className = "menu";
  op.value = "Null";
  txt = document.createTextNode("---");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "NOT";
  txt = document.createTextNode("NOT");
  op.appendChild(txt);
  select.appendChild(op);
  if (state < 2) {
    lista.appendChild(select);
  }
  if (state >= 2) {
    lista.insertBefore(select, document.getElementById("label2" + aux));
  }

  select = document.createElement("select");
  select.id = auxC + "Condi" + aux;
  op = document.createElement("option");
  op.className = "menu";
  op.value = "Null";
  txt = document.createTextNode("---");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "AND";
  txt = document.createTextNode("AND");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "OR";
  txt = document.createTextNode("OR");
  op.appendChild(txt);
  select.appendChild(op);
  
  Type_L=1;
  if (state < 2) {
    lista.appendChild(select);
  }
  if (state >= 2) {
    lista.insertBefore(select, document.getElementById("label2" + aux));
  }
  select.addEventListener("change", function change() {
    extra2 = extra.options[extra.selectedIndex].value;
    if(state==1){
    document.getElementById(auxV-1 + "selectVar" + aux).removeEventListener("change",Type_V_swich);
    }
  });
  select.addEventListener("change", Vari);
  select = document.createElement("select");
  select.id = auxC + "NOT2" + aux;
  op = document.createElement("option");
  op.className = "menu";
  op.value = "Null";
  txt = document.createTextNode("---");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "NOT";
  txt = document.createTextNode("NOT");
  op.appendChild(txt);
  select.appendChild(op);
  if (state < 2) {
    lista.appendChild(select);
  }
  if (state >= 2) {
    lista.insertBefore(select, document.getElementById("label2" + aux));
  }


  }
  if(type_V==2){
  select = document.createElement("select");
  select.id = auxC + "Condi" + aux;
  op = document.createElement("option");
  op.className = "menu";
  op.value = "Null";
  txt = document.createTextNode("---");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "MAYOR";
  txt = document.createTextNode("MAYOR");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "MENOR";
  txt = document.createTextNode("MENOR");
  op.appendChild(txt);
  select.appendChild(op);
Type_L=2; 
if (state < 2) {
    lista.appendChild(select);
  }
  if (state >= 2) {
    lista.insertBefore(select, document.getElementById("label2" + aux));
  }
  select.addEventListener("change", function change() {
    extra2 = extra.options[extra.selectedIndex].value;
    if(state==1){
    document.getElementById(auxV-1 + "selectVar" + aux).removeEventListener("change",Type_V_swich);
    }
  });
  select.addEventListener("change", Vari);

}
 
  auxC++;
  extra = document.getElementById(auxC - 1 + "Condi" + aux);
  extra2 = extra.options[extra.selectedIndex].value;
  
 
}
function Type_V_swich() {
    var aux_select;
    if(document.getElementById(auxC-1 + "Condi" + aux)!=null){
      document.getElementById(auxC-1 + "Condi" + aux).removeEventListener("change",Vari);
    }
    if(document.getElementById(auxV-1 + "selectVar" + aux)!=null){
 aux_select= document.getElementById(auxV-1 + "selectVar" + aux).options[document.getElementById(auxV-1 + "selectVar" + aux).selectedIndex].value;
    if(aux_select=="D1"||aux_select=="D2"||aux_select=="D3"||aux_select=="D4"||aux_select=="1S"||aux_select=="2S"||aux_select=="3S"||aux_select=="4S"){
       type_V=1; 
    }
    if(aux_select=="A1"||aux_select=="A2"||aux_select=="A3"||aux_select=="A4"){
       type_V=2; 
    }
}

console.log(type_V);
logi();
    
}

function final() {
  lista = document.getElementById("form" + aux);
  label = document.createElement("label");
  label.id = "label2" + aux;
  txt = document.createTextNode("THEN ");
  label.appendChild(txt);
  lista.appendChild(label);
  select = document.createElement("select");
  select.id = "salVar" + aux;
  op = document.createElement("option");
      op.className = "menu";
      op.value = "S1";
      txt = document.createTextNode("1S");
      op.appendChild(txt);
      select.appendChild(op);
      label.appendChild(select);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "S2";
      txt = document.createTextNode("2S");
      op.appendChild(txt);
      select.appendChild(op);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "S3";
      txt = document.createTextNode("3S");
      op.appendChild(txt);
      select.appendChild(op);
      op = document.createElement("option");
      op.className = "menu";
      op.value = "S4";
      txt = document.createTextNode("4S");
      op.appendChild(txt);
      select.appendChild(op);
  select = document.createElement("select");
  select.id = "sal" + aux;

  op = document.createElement("option");
  op.className = "menu";
  op.value = "Null";
  txt = document.createTextNode("---");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "SET";
  txt = document.createTextNode("SET");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "RESET";
  txt = document.createTextNode("RESET");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "SEGUIDORA";
  txt = document.createTextNode("SEGUIDORA");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "SET_MS";
  txt = document.createTextNode("SET_MS");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "SET_SEG";
  txt = document.createTextNode("SET_SEG");
  op.appendChild(txt);
  select.appendChild(op);
  op = document.createElement("option");
  op.className = "menu";
  op.value = "SET_MIN";
  txt = document.createTextNode("SET_MIN");
  op.appendChild(txt);
  select.appendChild(op);
  lista.append(select);
  console.log(state);
  select.addEventListener("change", function change() {
    extra2 = extra.options[extra.selectedIndex].value;
    state++;
    if (extra2 == "Null") {
      lista.removeChild(extra);
      if(document.getElementById(auxC-1 + "NOT2" + aux!=null)){
      lista.removeChild(document.getElementById(auxC-1 + "NOT2" + aux))
    }
      auxC--;
    }
 aux_select= document.getElementById("sal" + aux).options[document.getElementById("sal" + aux).selectedIndex].value;
    
 if(aux_select=="SET_MS"){
     select=document.createElement("input");
     select.type="range";
     select.min="10";
     select.max="3000";
     select.value="10";
     select.id="slider"+aux;
     lista.append(select);
     select=document.createElement("span");
     select.id="span"+aux;
     console.log("en tiempo");
     lista.append(select);
     
    }
    if(aux_select=="SET_SEG"){
     select=document.createElement("input");
     select.type="range";
     select.min="10";
     select.max="300";
     select.value="1";
     select.id="slider"+aux;
     lista.append(select);
     select=document.createElement("span");
     select.id="span"+aux;
     console.log("en tiempo");
     lista.append(select);
     
    }
    if(aux_select=="SET_MIN"){
     select=document.createElement("input");
     select.type="range";
     select.min="1";
     select.max="300";
     select.value="1";
     select.id="slider"+aux;
     lista.append(select);
     select=document.createElement("span");
     select.id="span"+aux;
     console.log("en tiempo");
     lista.append(select);
     
    }}
  
  );
  lista.addEventListener("change", function then() {
    if(document.getElementById("slider"+aux)!=null){
    var slider = document.getElementById("slider"+aux);
  console.log(slider.value);
  document.getElementById("span"+aux).innerHTML=slider.value;}
  });
}



function Borrar() {
  var panda = document.getElementById("cuadro");
  panda.removeChild(panda.lastElementChild);
  aux--;
  state = 0;
  type_V=0;
  Type_L=0;
}
function Programar() {
     
 if( document.getElementById("sal" + aux).options[document.getElementById("sal" + aux).selectedIndex].value!="Null"){
  Envio();
  BorrarTodo();
  }
}
function Ejecutar() {
  var data_send=new XMLHttpRequest();
  data_send.open("GET","ejecutar",true);
  data_send.send();
}
function Pausar() {
  var data_send=new XMLHttpRequest();
  data_send.open("GET","pausar",true);
  data_send.send(); 
}
function Detener() {
  var data_send=new XMLHttpRequest();
  data_send.open("GET","detener",true);
  data_send.send(); 
}
function BorrarTodo() {
  var panda = document.getElementById("cuadro");
  while (aux >= 1) {
    panda.removeChild(panda.lastElementChild);
    aux--;
  }
  aux = 0;
  aux2 = 0;
  state = 0;
}
setInterval(function () {
 var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Inst").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "tasks", true);
  xhttp.send();
 
},600)
function Envio() {
   var info={};
  var ind;
  var va;
  var vanot;
  var va2;
  var va3;
  var va4;
  var vaslider;
  var jsonn;
  var jsonnn;
  var data_send=new XMLHttpRequest();
  console.log("en envio")
  
  console.log(aux);
  for(var j=1;j<=aux;j++){
  
  for(var i=0;document.getElementById(i + "selectVar" + j)!=null||document.getElementById(i + "Condi" + j)!=null||document.getElementById(i + "NOT" + j)!=null;i++){
    if(document.getElementById(i + "selectVar" + j)!=null){
  va2 = document.getElementById(i + "selectVar" + j).options[document.getElementById(i + "selectVar" + j).selectedIndex].value;
  ind=j+"_var_"+i;
  info[ind]=va2;
  }
  if(document.getElementById(i + "NOT" + j)!=null){
    
    vanot = document.getElementById(i + "NOT" + j).options[document.getElementById(i + "NOT" + j).selectedIndex].value;
    ind=i + "NOT" + j;
    info[ind]=vanot;
  }
  if(document.getElementById(i + "Condi" + j)!=null){
  if(i<auxC){
    va = document.getElementById(i + "Condi" + j).options[document.getElementById(i + "Condi" + j).selectedIndex].value;
    ind=j+"_logi_"+i;
    info[ind]=va;}
  }
  if(document.getElementById(i + "NOT2" + j)!=null){
    
    vanot = document.getElementById(i + "NOT2" + j).options[document.getElementById(i + "NOT2" + j).selectedIndex].value;
    ind=i + "NOT2" + j;
    info[ind]=vanot;
  }}
  info["Then"]="Then";
  va3 = document.getElementById("sal" + j).options[document.getElementById("sal" + j).selectedIndex].value;
  va4 = document.getElementById("salVar" + j).options[document.getElementById("salVar" + j).selectedIndex].value;
  
  ind=j+"_SalVar";
  info[ind]=va4;
  ind=j+"_Cond";  
  info[ind]=va3;
  if(va3=="SET_MS"||va3=="SET_SEG"||va3=="SET_MIN"){
    vaslider=document.getElementById("slider"+j).value;
  ind=j+"slider";
  info[ind]=vaslider;
  }
  info["EndLine"+j]="True";
  }


jsonn=JSON.stringify(info);
localStorage.setItem("miJSON",jsonn);
jsonnn=localStorage.getItem("miJSON");
console.log(jsonn);
data_send.open("POST","info?informacion="+jsonn,true);
data_send.send();
}</script>
)***";
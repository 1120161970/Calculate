function GetRandomNum(Min,Max){ 
  var Range = Max - Min; 
  var Rand = Math.random(); 
  return(Min + Math.round(Rand * Range)); 
}
// 获取随机数
function max_num(x,y) {
 var t;
 while (y) {
  t = x%y;
  x = y;
  y = t;
 }
 return x;
}
function fenshu(a,b,p) {
 if (p==1) {
  if (a>b) {
   return a+"/"+b;
  }else if(a<b){
   return a+"/"+b;
  }else {
   return 1;
  }
 }else {
  var x=a/p;
  var y=b/p;
  if(y==1){
   return x;
  }else{
   return x+"/"+y;
  }
 }
}
function f_count(a,b,c,d) {
  var Arr = ["+","-","*","/"]; 
  var n = GetRandomNum(0,3);
  switch(Arr[n]){
   case "+":{
   var sum_x=(a*d)+(b*c);
   var sum_y=b*d;
   max_x=max_num(sum_x,sum_y);
   max_y=max_num(sum_x,sum_y);
   var N=fenshu(sum_x,sum_y,max_x);
   return a+"/"+b+"+"+c+"/"+d+"="+N;
   break;
   }
   case "-":{
   var sum_x=(a*d)-(b*c);
    while (sum_x<0) {
     var a = GetRandomNum(1,30); 
     var b = GetRandomNum(1,30);
     var c = GetRandomNum(1,30); 
     var d = GetRandomNum(1,30);
     var sum_x=(a*d)-(b*c);
    }
   var sum_y=b*d;
   max_x=max_num(sum_x,sum_y);
   max_y=max_num(sum_x,sum_y);
   var N=fenshu(sum_x,sum_y,max_x);
   return a+"/"+b+"-"+c+"/"+d+"="+N;
   break;
   }
   case "*":{
   var sum_x=a*c;
   var sum_y=b*d;
   max_x=max_num(sum_x,sum_y);
   max_y=max_num(sum_x,sum_y);
   var N=fenshu(sum_x,sum_y,max_x);
   return a+"/"+b+"*"+c+"/"+d+"="+N;
   break;
   }
   case "/":{
   var sum_x=a*d;
   var sum_y=b*c;
   max_x=max_num(sum_x,sum_y);
   max_y=max_num(sum_x,sum_y);
   var N=fenshu(sum_x,sum_y,max_x);
   return a+"/"+b+"÷"+c+"/"+d+"="+N;
   break;
   }
  }
}
function count(a,b){
  var Arr = ["+","-","*","/"]; 
  var n = GetRandomNum(0,3);
  switch(Arr[n]){
   case "+":{
   var sum=a+b;
   return a+"+"+b+"="+sum;
   break;
   }
   case "-":{
   var sum=a-b;
   while(sum<0){
    var a = GetRandomNum(1,30);
    var b = GetRandomNum(1,30);
    var sum=a-b;
   }
   return a+"-"+b+"="+sum;
   break;
   }
   case "*":{
   var sum=a*b;
   return a+"*"+b+"="+sum;
   break;
   }
   case "/":{
   var sum=a/b;
   while(a%b!==0){
    var max_x=max_num(a,b);
    var N=fenshu(a,b,max_x);
    return a+"÷"+b+"="+N;
   }
   return a+"÷"+b+"="+sum;
   break;
   }
  }
}
function pl_f() {
 var son_a = GetRandomNum(1,30); 
 var par_b = GetRandomNum(1,30);
 var son_c = GetRandomNum(1,30); 
 var par_d = GetRandomNum(1,30);
 var suma=f_count(son_a,par_b,son_c,par_d);
 return suma;
}
function pl() {
  var a = GetRandomNum(1,30); 
  var b = GetRandomNum(1,30);
  var sumb=count(a,b);
  return sumb;
}

function play_all() {
  // var flag = 0;
  var a = document.getElementById("tp").value;
  var inta = parseInt(a);
  for (i = 1; i <= inta; i++) {
   var a = GetRandomNum(0,1);
   document.getElementById("text").innerHTML+=("<br>"+"第"+i+"题：");
   switch (a) {
    case 0:
     var A=pl();
     var strs = A.split("=");
     document.getElementById("text").innerHTML+=(strs[0]+"="+"<input>"+"<button>提交</button>"+"<br>");
     document.getElementById("text2").innerHTML+=("<br>"+"第"+i+"题答案："+"<span>"+strs[1]+"</span>"+"<br>");
     break;
    case 1:
     var B=pl_f();
     var strs = B.split("=");
     document.getElementById("text").innerHTML+=(strs[0]+"="+"<input>"+"<button>提交</button>"+"<br>");
     document.getElementById("text2").innerHTML+=("<br>"+"第"+i+"题答案："+"<span>"+strs[1]+"</sapn>"+"<br>");
     break;
   }
  }
}
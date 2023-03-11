
let maino=async ()=>{
let one=async ()=>{
    let p1=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("resolved in  2 secs")
        },2000)
    })
    // return p1;
//     p1.then((x)=>{
//  console.log(x)
// })

    let a=await p1;
    return a;
    // return p1;
    // console.log(a)
    // console.log(p1)
  //  return p1;  //yeh p1 ke resolve ke value ko return krey ga
    //ager yeh use nahi krty hain tu sirf promise return hoga witout 
    // its values
   
}
let a=await one();
    // let a=one();
console.log(a)
 // one().then(alert)}
}
maino();

//Conclusion
/*
normal function kuch bhi beghari batai return nahi krta 
async funciton normally promise return krta hai without values aka values insie warp hoti hain
ager hum kahein pr bhi await ka keryword use kr dein gay tu fir wo us ke ander us ke value store kr le ga


or upar yeh ho rha hai ke jbb hum async function ke bahir await use kr rhy hain tu wo sirf value return krta hai or normally jo async function hai wo value undefined he hoti hai jbb tk btao na tu is lie value async function ke ander se return krny prey gi normally

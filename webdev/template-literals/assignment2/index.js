const fields = [ 
  "First Name", 
  "Last Name", 
  "Email"
];

function getBody(fields){
    let template = ``;
    fields.map((field)=>{
        
        template+= `<label>\n${field}</label>\n<input type="text" />\n`
    })
    return template;
}
const element = document.getElementById("user-form");
console.log(getBody(fields))
element.innerHTML= getBody(fields);
console.log("fields populated")
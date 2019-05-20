import axios from 'axios';

class MyClass {

    static async getUserInfo(username) {
        const response = await axios.get(`https://api.github.com/users/${username}`)
        return response;
    }

}

  
document.getElementById("botao").onclick = async () => {
    console.log(document.getElementById("texto").value);
    var k = await MyClass.getUserInfo(document.getElementById("texto").value);
    //console.log(JSON.stringify(k.data));


    document.getElementById("areatexto").innerText = JSON.stringify(k);
}

const printLine = () => console.log("----------------------");


// 1
class Usuario {
    constructor(email, senha) {
        this.email = email,
        this.senha = senha;
        this.admin = false;
    }

    setUserAsAdmin() {
        this.admin = true;
    }

    isAdmin() {
        return this.admin;
    }
}


class Admin extends Usuario {
    constructor(email, senha) {
        super(email, senha);
        super.setUserAsAdmin();
    }
}


const User1 = new Usuario('email@teste.com', 'senha123');
const Adm1 = new Admin('email@teste.com', 'senha123');

console.log(User1.isAdmin()); // false
console.log(Adm1.isAdmin()); // true



// 2
printLine();

const usuarios = [
    { nome: 'Diego', idade: 23, empresa: 'Rocketseat' },
    { nome: 'Gabriel', idade: 15, empresa: 'Rocketseat' },  
    { nome: 'Lucas', idade: 30, empresa: 'Facebook' },
];

const idades = usuarios.map( usuarios => usuarios.idade );
console.log(idades);

const empregadosRocketSeat = usuarios.filter( usuarios => usuarios.idade > 18 && usuarios.empresa === 'Rocketseat' );
console.log(empregadosRocketSeat);

const empregadosGoogle = usuarios.find( usuarios => usuarios.empresa === 'Google' );
console.log(empregadosGoogle);

const empregadosTwice = usuarios.map( usuarios => {
    return { ...usuarios, idade: usuarios.idade * 2 };
});
console.log(empregadosTwice.filter( usuarios => usuarios.idade < 50 ));


const printLine = () => console.log("----------------------");

/*
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



// 3
printLine();
// 3.1
const arr = [1, 2, 3, 4, 5];
console.log(arr.map( item => item + 10 ));

//3.2
const usuario = { nome: 'Diego', idade: 23 };

const mostraIdade = (usuario) => usuario.idade;
console.log(mostraIdade(usuario));

// 3.3
const nome = "Diego";
const idade = 23;

const mostraUsuario = (nome = 'Diego', idade = 18) => ({nome, idade});

console.log(mostraUsuario(nome, idade));
console.log(mostraUsuario(nome));



// 4
printLine();
// 4.1
const empresa = {
    nome: 'Rocketseat',
    endereco: {
    cidade: 'Rio do Sul',
    estado: 'SC',
    }
};

const {nome, endereco: {cidade, estado}} = empresa;

console.log(nome); // Rocketseat
console.log(cidade); // Rio do Sul
console.log(estado); // SC


//4.2
function mostraInfo(usuario) {
    let {nome, idade} = usuario;
    return `${nome} tem ${idade} anos.`;
}

console.log(mostraInfo({ nome: 'Diego', idade: 23 }));
*/


// 5
printLine();
// 5.1
const myArray = [1, 2, 3, 4, 5, 6];

const [ x, ...y ] = myArray;

console.log(x); // 1
console.log(y); // [2, 3, 4, 5, 6]
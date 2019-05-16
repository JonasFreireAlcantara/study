const animal = {
    nome: "Beethoven",
    idade: 8,
    caracteristicas: {
        cor: "marrom",
        altura: "85 cm",
        peso: "19 kg"
    }
};

console.log(animal);


// const nome = animal.nome;
// const idade = animal.idade;
// const peso = animal.caracteristicas.peso;

// console.log(nome);
// console.log(idade);
// console.log(peso);


const { nome, idade, caracteristicas: {peso} } = animal;

console.log(nome);
console.log(idade);
console.log(peso);
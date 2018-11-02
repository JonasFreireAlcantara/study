Explicação sobre scripts em Python

De fato um projeto do tipo CRUD em python ainda não fiz, porém utilizei python para resolver alguns problemas e como ferramenta de estudo.

Atualmente utilizo o python mais como um resolvedor de problemas, quando percebo alguma atividade repetitiva que pode ser automatizada, python é a primeira ferramenta que vem a minha mente, por exemplo, uma expressão algébrica na disciplina de IA ou alguma rotina em Estatística.

Pus dois arquivos na pasta.

- 'orbita.py':
	Durante a disciplina de Física Aplicada a Computação, nós utilizamos uma biblioteca escrita em Python para simulação de fenômenos físicos, o script em questão simula a órbita de dois corpos celestes que obedecem a lei da gravitação universal.

- 'script_assembly.py':
	Durante a disciplina de Arquitetura de Computadores, nós precisávamos desenvolver um projeto que basicamente consistia em implementar o jogo PacMan em Assembly MIPS, toda a tela deveria ser criada 'pintando' pixel a pixel, o que era uma atividade muito repetitiva e sujeita a erros, normalmente nós utilizávamos uma planilha, onde cada célula representava um pixel na tela, a partir daí utilizávamos a planilha como guia para 'pintar' o pixel através das instruções, mas como eram 64 x 32 pixels, eram 2048 pixels, 2048 instruções para se codificar, e como eram duas telas, era muito trabalho repetitivo.

	A solução foi utilizar o python, como o python tem bibliotecas que facilitam a vida, utilizei a classe de leitura de XML, como a planilha gerava um XML, o script iria ler o XML e gerar todo o código em assembly necessário em alguns segundos, livre de erro vindo de repetição desnecessária.

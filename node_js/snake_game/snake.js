/**
 * Data Strucuture info
 * 0 - empty position
 * 1 - snake body
 * 2 - eat body
 * 3 - obstacle
 */
let board = [];
const width = 10;
const height = 10;
const pallete = [{r:0,g:0,b:0}, {r:0,g:255,b:0}, {r:255,g:0,b:0}, {r:0,g:0,b:255}]


function createDataStructure() {
  const totalSize = width * height;

  for (let i = 0; i < totalSize; i++) {
    board[i] = 0;
  }

  const snakeInitialPosition = Math.floor(Math.random() * totalSize);
  board[snakeInitialPosition] = 1;
}


function renderGame() {
  let html = '<table>';

  for (let row = 0; row < height; row++) {
    html += '<tr>'

    for (let column = 0; column < width; column++) {
      const pixelIndex = (width * row) + column;
      const pixelValue = board[pixelIndex];
      const color = pallete[pixelValue];
      const colorString = `rgb(${color.r},${color.g},${color.b})`;

      html += `<td style="background:${colorString}"></td>`
    }
    html += '</tr>'
  }
  html += '</table>';

  document.getElementById('board-game').innerHTML = html;
}

function moveSnake() {

}

function increaseSnake() {

}

function executeStep() {

}

function gameOver() {

}

function start() {
  createDataStructure();
  renderGame();
}

start();




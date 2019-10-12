/**
 * Data Strucuture info
 * 0 - empty position
 * 1 - snake head
 * 2 - snake body
 * 3 - eat body
 * 4 - obstacle
 */
let board = [];
const width = 10;
const height = 10;
const pallete = [{r:0,g:0,b:0}, {r:0,g:255,b:0}, {r:0,g:100,b:20}, {r:255,g:0,b:0}, {r:0,g:0,b:255}];


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

function removeSnakeRear() {
  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 2) {
        const topPixelIndex = (pixelIndex - width) >= 0 ? (pixelIndex - width) : (width*height) - width + column;
        const bottomPixelIndex = (pixelIndex + width) >= (width*height) ? column : (pixelIndex + width); 
        const leftPixelIndex = (pixelIndex - 1) >= (row*width) ? (pixelIndex - 1) : (row*width) - width;
        const rightPixelIndex = (pixelIndex + 1) <= ((row*width)+width) ? (pixelIndex + 1) : (row*width);

        const topPixelValue = board[topPixelIndex];
        const bottomPixelValue = board[bottomPixelIndex];
        const leftPixelValue = board[leftPixelIndex];
        const rightPixelValue = board[rightPixelIndex];

        let total = 0;
        
        if (topPixelValue == 1 || topPixelValue == 2) {
          total++;
        }
        if (bottomPixelValue == 1 || bottomPixelValue == 2) {
          total++;
        }
        if (leftPixelValue == 1 || leftPixelValue == 2) {
          total++;
        }
        if (rightPixelValue == 1 || rightPixelValue == 2) {
          total++;
        }

        if (total == 1) { // is snake rear
          board[pixelIndex] = 0;
        }

      }
    }
  }

}

function moveUpSnake(grow) {
  
  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 1) {
        const abovePixelIndex = (pixelIndex - width) >= 0 ? (pixelIndex - width) : (width*height) - width + column;
        board[abovePixelIndex] = 1;
        board[pixelIndex] = 2;
      }

    }
  }

  if (!grow) {
    removeSnakeRear();
  }
  renderGame();
}

function moveDownSnake() {

}

function moveRightSnake() {

}

function moveLeftSnake() {

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

  moveUpSnake(true);

  setInterval(moveUpSnake, 1000);
}

start();




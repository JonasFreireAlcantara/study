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
const keyCodes = {
  37: 'left',
  38: 'up',
  39: 'right',
  40: 'down'
};
let direction = 'up';
let directionChanged = false;


function createDataStructure() {
  const totalSize = width * height;

  for (let i = 0; i < totalSize; i++) {
    board[i] = 0;
  }

  const snakeInitialPosition = Math.floor(Math.random() * totalSize);
  board[snakeInitialPosition] = 1;
}


function renderGame() {
  let html = '<table cellpading=0 cellspacing=0 >';

  for (let row = 0; row < height; row++) {
    html += '<tr>'

    for (let column = 0; column < width; column++) {
      const pixelIndex = (width * row) + column;
      const pixelValue = board[pixelIndex];
      const color = pallete[pixelValue];
      const colorString = `rgb(${color.r},${color.g},${color.b})`;

      html += `<td style="background:${colorString}"></td>`
      // html += `<td style="color:${colorString}">${pixelIndex}</td>`
    }
    html += '</tr>'
  }
  html += '</table>';

  document.getElementById('board-game').innerHTML = html;
  directionChanged = false;
}


function removeSnakeRear() {
  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 2) {
        const topPixelIndex = (pixelIndex - width) >= 0 ? (pixelIndex - width) : (width*height) - width + column;
        const bottomPixelIndex = (pixelIndex + width) >= (width*height) ? column : (pixelIndex + width); 
        const leftPixelIndex = (pixelIndex - 1) >= (row*width) ? (pixelIndex - 1) : (row*width) + width - 1;
        const rightPixelIndex = (pixelIndex + 1) < ((row+1)*width) ? (pixelIndex + 1) : (row*width);

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
          row = height;
          column = width;
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
        row = height;
        column = width;
      }
    }
  }

  if (!grow) {
    removeSnakeRear();
  }
  renderGame();
}


function moveDownSnake(grow) {

  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 1) {
        const bottomPixelIndex = (pixelIndex + width) >= (width*height) ? column : (pixelIndex + width); 
        board[bottomPixelIndex] = 1;
        board[pixelIndex] = 2;
        row = height;
        column = width;
      }
    }
  }

  if (!grow) {
    removeSnakeRear();
  }
  renderGame();
}


function moveRightSnake(grow) {

  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 1) {
        const rightPixelIndex = (pixelIndex + 1) < ((row+1)*width) ? (pixelIndex + 1) : (row*width);
        board[rightPixelIndex] = 1;
        board[pixelIndex] = 2;
        row = height;
        column = width;
      }
    }
  }

  if (!grow) {
    removeSnakeRear();
  }
  renderGame();
}

function moveLeftSnake(grow) {

  for (let row = 0; row < height; row++) {
    for (let column = 0; column < width; column++) {
      const pixelIndex = (row * width) + column;
      const pixelValue = board[pixelIndex];

      if (pixelValue == 1) {
        const leftPixelIndex = (pixelIndex - 1) >= (row*width) ? (pixelIndex - 1) : (row*width) + width - 1;
        board[leftPixelIndex] = 1;
        board[pixelIndex] = 2;
        row = height;
        column = width;
      }
    }
  }

  if (!grow) {
    removeSnakeRear();
  }
  renderGame();
}


function executeStep() {
  if (directionChanged) {
    renderGame();
    return;
  }

  switch (direction) {
    case 'up':
      moveUpSnake();
      break;

    case 'right':
        moveRightSnake();
      break;

    case 'down':
        moveDownSnake();
      break;

    case 'left':
        moveLeftSnake();
        break;
      }
      
      renderGame();
}

function changeDirection(event) {
  let keyCode = event.keyCode;
  
  switch (keyCodes[keyCode]) {
    case 'up':
      if (direction != 'down') {
        direction = 'up';
        directionChanged = true;
      }
      break;
    
    case 'down':
      if (direction != 'up') {
        direction = 'down';
        directionChanged = true;
      }
      break;

    case 'left':
      if (direction != 'right') {
        direction = 'left';
        directionChanged = true;
      }
      break;

    case 'right':
      if (direction != 'left') {
        direction = 'right';
        directionChanged = true;
      }
      break;
  }

}

function gameOver() {

}

function start() {
  document.addEventListener('keydown', changeDirection, false);

  createDataStructure();
  renderGame();

  moveUpSnake(true);
  moveUpSnake(true);
  moveUpSnake(true);

  setInterval(executeStep, 100);
}

start();




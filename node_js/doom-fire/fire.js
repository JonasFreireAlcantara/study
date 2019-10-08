const firePixelsArray = [];
let fireWidth = 120;
let fireHeight = 40;
let sentido = 0;
const fireColorsPalette = [{"r":7,"g":7,"b":7},{"r":31,"g":7,"b":7},{"r":47,"g":15,"b":7},{"r":71,"g":15,"b":7},{"r":87,"g":23,"b":7},{"r":103,"g":31,"b":7},{"r":119,"g":31,"b":7},{"r":143,"g":39,"b":7},{"r":159,"g":47,"b":7},{"r":175,"g":63,"b":7},{"r":191,"g":71,"b":7},{"r":199,"g":71,"b":7},{"r":223,"g":79,"b":7},{"r":223,"g":87,"b":7},{"r":223,"g":87,"b":7},{"r":215,"g":95,"b":7},{"r":215,"g":95,"b":7},{"r":215,"g":103,"b":15},{"r":207,"g":111,"b":15},{"r":207,"g":119,"b":15},{"r":207,"g":127,"b":15},{"r":207,"g":135,"b":23},{"r":199,"g":135,"b":23},{"r":199,"g":143,"b":23},{"r":199,"g":151,"b":31},{"r":191,"g":159,"b":31},{"r":191,"g":159,"b":31},{"r":191,"g":167,"b":39},{"r":191,"g":167,"b":39},{"r":191,"g":175,"b":47},{"r":183,"g":175,"b":47},{"r":183,"g":183,"b":47},{"r":183,"g":183,"b":55},{"r":207,"g":207,"b":111},{"r":223,"g":223,"b":159},{"r":239,"g":239,"b":199},{"r":255,"g":255,"b":255}]


function start() {
    createFireDataStructure();
    createFireSource();

    setInterval(calculateFirePropagation, 1);
}

function changeWindDirection(value) {
    sentido = value;
}

function createFireDataStructure() {
    const numberOfPixels = fireWidth * fireHeight;

    for (let i = 0; i < numberOfPixels; i++) {
        firePixelsArray[i] = 0;
    }
}

function calculateFirePropagation() {
    for (let column = 0; column < fireWidth; column++) {
        for (let row = 0; row < fireHeight; row++) {
            const pixelIndex = column + (fireWidth * row);

            updateFireIntensityPerPixel(pixelIndex);
        }
    }

    renderFire();
}

function renderFire() {
    let html = '<table cellpadding=0 cellspacing=0 >'

    for (let row = 0; row < fireHeight; row++) {
        html += '<tr>'

        for (let column = 0; column < fireWidth; column++) {
            const pixelIndex = column + (fireWidth * row);
            const fireIntensity = firePixelsArray[pixelIndex];
            const color = fireColorsPalette[fireIntensity];
            const colorString = `${color.r},${color.g},${color.b}`;

            html += `<td class="pixel" style="background: rgb(${colorString})">`
            //html += `<td class="pixel">${fireIntensity}`;
            html += '</td>';
        }

        html += '</tr>';
    }
    html += '</table>';

    document.querySelector('#fireCanvas').innerHTML = html;
}

function updateFireIntensityPerPixel(currentPixelIndex) {
    const belowPixelIndex = currentPixelIndex + fireWidth;

    if (belowPixelIndex >= fireWidth * fireHeight) {
        return;
    }

    const decay = Math.ceil(Math.random() * 1);
    const windDirection = Math.floor(Math.random() * 3) - 1;
    const belowPixelFireIntensity = firePixelsArray[belowPixelIndex];
    let newFireIntensity = (belowPixelFireIntensity - decay) >= 0 ? (belowPixelFireIntensity - decay) : 0;

    firePixelsArray[currentPixelIndex + windDirection] = newFireIntensity; // left
}

function setFireSource(value) {
    const overflowPixelIndex = fireWidth * fireHeight;
    for (let column = 0; column <= fireWidth; column++) {
        const pixelIndex = (overflowPixelIndex - fireWidth) + column;
        firePixelsArray[pixelIndex] = value;
    }
}

function createFireSource() {
    setFireSource(36);
}

function increaseFireSource() {
    const overflowPixelIndex = fireWidth * fireHeight;

    for (let column = 0; column < fireWidth; column++) {
        const increase = Math.floor(Math.random() * 14);
        const pixelIndex = (overflowPixelIndex - fireWidth) + column;
        const currentFireIntensity = firePixelsArray[pixelIndex];
        const newFireIntensity = (currentFireIntensity + increase) > 36 ? 36 : (currentFireIntensity + increase);
        
        firePixelsArray[pixelIndex] = newFireIntensity;
    }
}

function decreaseFireSource() {
    const overflowPixelIndex = fireWidth * fireHeight;

    for (let column = 0; column < fireWidth; column++) {
        const decay = Math.floor(Math.random() * 14);
        const pixelIndex = (overflowPixelIndex - fireWidth) + column;
        const currentFireIntensity = firePixelsArray[pixelIndex];
        const newFireIntensity = (currentFireIntensity - decay) < 0 ? 0 : (currentFireIntensity - decay);

        firePixelsArray[pixelIndex] = newFireIntensity;
    }
}


start();
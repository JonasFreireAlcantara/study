function promptUserForHoursPerDayInWeek() {
    return {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        satuday
    }
}


function promptUserForHoursAmountNeeded() {
    return hoursAmountNeeded();
}


function promptUserForHolidays() {
    return holidays;
}


function promptUserForFirstDay() {
    return initialDay;
}


function computeIntervalDate() {

    const firstDay = promptUserForFirstDay();
    const hoursPer = promptUserForHoursPerDayInWeek();
    const holidays = promptUserForHolidays();
    const hoursAmountNeeded = promptUserForHoursAmountNeeded();

    var numberOfHours = 0;
    
    while( numberOfHours < hoursAmountNeeded) {
        
    }

    

    return {
        numberOfDays,
        initialDay,
        finalDay
    }
}

function printInformation() {

}
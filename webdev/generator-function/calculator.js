function* calculator(initialValue) {
    let result = initialValue;

    while (true) {
        const command = yield result;

        switch (command.operation) {
            case "add":
                result += command.value;
                break;

            case "subtract":
                result -= command.value;
                break;

            case "multiply":
                result *= command.value;
                break;

            case "divide":
                result /= command.value;
                break;

            default:
                console.log("Unknown operation");
        }
    }
}

const calc = calculator(50);

console.log(calc.next().value); 
console.log(calc.next({ operation: "add", value: 30 }).value);
console.log(calc.next({ operation: "multiply", value: 2 }).value);
console.log(calc.next({ operation: "add", value: 30 }).value);
console.log(calc.next({ operation: "multiply", value: 0 }).value);
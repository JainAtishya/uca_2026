function MyPromise(executorFunction) {

    let state = "pending";
    let value;
    let error;

    let thenCallbacks = [];
    let catchCallbacks = [];

    function resolve(result) {
        if (state !== "pending") {
            return;
        }

        state = "fulfilled";
        value = result;

        thenCallbacks.forEach(callback => {
            callback(value);
        });
    }

    function reject(err) {
        if (state !== "pending") {
            return;
        }

        state = "rejected";
        error = err;

        catchCallbacks.forEach(callback => {
            callback(error);
        });
    }

    this.then = function(callback) {

        return new MyPromise((resolveNext, rejectNext) => {

            function handleThen() {
                try {
                    let result = callback(value);

                    // If callback returns another MyPromise
                    if (result instanceof MyPromise) {
                        result.then(resolveNext).catch(rejectNext);
                    } else {
                        resolveNext(result);
                    }

                } catch (err) {
                    rejectNext(err);
                }
            }

            if (state === "fulfilled") {
                handleThen();
            } else if (state === "pending") {
                thenCallbacks.push(handleThen);
            }
        });
    };

    this.catch = function(callback) {

        return new MyPromise((resolveNext, rejectNext) => {

            function handleCatch() {
                try {
                    let result = callback(error);
                    resolveNext(result);
                } catch (err) {
                    rejectNext(err);
                }
            }

            if (state === "rejected") {
                handleCatch();
            } else if (state === "pending") {
                catchCallbacks.push(handleCatch);
            }
        });
    };

    try {
        executorFunction(resolve, reject);
    } catch (err) {
        reject(err);
    }
}


new MyPromise(resolve => {
    resolve(5);
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log(value);
});
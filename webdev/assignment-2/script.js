const worker = new Worker("worker.js");

const usersDiv = document.getElementById("users");

worker.onmessage = function (event) {

    const { success, data, message } = event.data;

    if (!success) {
        usersDiv.textContent = message;
        return;
    }

    data.forEach(user => {

        const p = document.createElement("p");
        p.textContent = user;
        usersDiv.appendChild(p);

    });

};

worker.onerror = function (error) {

    usersDiv.textContent = "Worker Error: " + error.message;

};

worker.postMessage({});
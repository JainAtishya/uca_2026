const worker = new Worker("worker.js");

async function fetchUsers() {
    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        const users = data.users;

        if (!users || users.length === 0) {
            throw new Error("No users returned");
        }

        worker.postMessage(users);

    } catch (error) {
        console.error(error.message);
    }
}

worker.onmessage = function (event) {
    event.data.forEach(user => console.log(user));
};

fetchUsers();
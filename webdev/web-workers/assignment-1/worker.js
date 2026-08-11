self.onmessage = function (event) {

    const users = event.data;

    const result = users.map(user => {

        const status =
            user.id % 2 === 0
            ? "Active"
            : "Inactive";

        return `${user.firstName} ${user.lastName} - ${status}`;

    });

    self.postMessage(result);
};
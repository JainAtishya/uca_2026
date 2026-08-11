self.onmessage = async function () {

    try {

        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        const users = data.users;

        if (!users || users.length === 0) {
            throw new Error("No users found");
        }

        const result = users.map(user => {

            const status = user.id % 2 === 0
                ? "Active"
                : "Inactive";

            return `${user.firstName} ${user.lastName} - ${status}`;

        });

        self.postMessage({
            success: true,
            data: result
        });

    } catch (error) {

        self.postMessage({
            success: false,
            message: error.message
        });

    }

};
# Project Setup

To initialize the project, ensure you have the following dependencies:

- npm and npx: version 10.8.2 (for both BACKEND and FRONTEND)
- docker: version 27.2.0 (for BACKEND)

Once you're in the **frontend** and **backend** repositories, run the following command to install all the project dependencies:

```bash
npm i
```

## Starting Each Part

To start the frontend, run this command from the root of the **frontend** directory:

```bash
npm start
```

To start the backend, execute the **setup.sh** script from the root of the **backend** directory. The script provides two options:

```
script.sh "create" -> Creates the Prisma database before starting the backend
script.sh -> Starts the backend
```

**Note:** The backend script will launch a Docker container to handle the database.
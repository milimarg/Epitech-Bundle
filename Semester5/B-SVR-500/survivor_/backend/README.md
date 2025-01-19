# BackEnd

To ensure an optimal and high-performing BackEnd, we decided to separate it into two distinct parts:

- data management
- communication with the FrontEnd via routes.

## Data Management and Retrieval

### PostgreSQL

For data storage, we chose `PostgreSQL`, a widely used and very easy-to-use database management system.

### Prisma

To simplify data creation from PostgreSQL, we used an ORM (Object-Relational Mapping) called `Prisma`, which facilitates data creation and retrieval.

## Routes

To allow the FrontEnd to request information from the BackEnd, we implemented a `routing system` that can be pinged to retrieve various pieces of information.

### Express

For this, we used the `Express` library, which makes it easy to set up routes and manage their usage.

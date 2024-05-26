FROM maven:3.8.4-jdk-11-slim AS builder

RUN mkdir /src/

COPY pom.xml /
COPY src/ /src/

RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:11-jre-slim

COPY --from=builder /target/worker-jar-with-dependencies.jar /

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]

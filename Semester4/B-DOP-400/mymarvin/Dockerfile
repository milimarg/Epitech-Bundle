FROM jenkins/jenkins:lts

RUN jenkins-plugin-cli --plugins configuration-as-code:1775.v810dc950b_514
RUN jenkins-plugin-cli --plugins job-dsl:1.87
RUN jenkins-plugin-cli --plugins cloudbees-folder:6.901.vb_4c7a_da_75da_3
RUN jenkins-plugin-cli --plugins credentials:1337.v60b_d7b_c7b_c9f
RUN jenkins-plugin-cli --plugins github:1.38.0
RUN jenkins-plugin-cli --plugins instance-identity:185.v303dc7c645f9
RUN jenkins-plugin-cli --plugins script-security:1326.vdb_c154de8669
RUN jenkins-plugin-cli --plugins structs:337.v1b_04ea_4df7c8
RUN jenkins-plugin-cli --plugins role-strategy:711.vf33a_d2c994b_a_
RUN jenkins-plugin-cli --plugins ws-cleanup:0.45

COPY my_marvin.yml /var/jenkins_home
COPY job_dsl.groovy /var/jenkins_home

ENV CASC_JENKINS_CONFIG /var/jenkins_home/my_marvin.yml
ENV USER_CHOCOLATEEN_PASSWORD toddler
ENV USER_NASSO_PASSWORD miaou
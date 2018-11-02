pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                cmake .
                make
            }
        }
        stage('Test') {
            steps {
                ./proxy
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
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
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
#!/usr/bin/env groovy

String path = "Tools"

folder(path) {
    displayName(path)
    description('Folder for miscellaneous tools.')
}

freeStyleJob("$path/clone-repository") {
    parameters {
        stringParam('GIT_REPOSITORY_URL', '', 'Git URL of the repository to clone')
    }

    steps {
        shell('git clone $GIT_REPOSITORY_URL')
    }

    wrappers {
        preBuildCleanup()
    }
}

freeStyleJob("$path/SEED") {
    parameters {
        stringParam('GITHUB_NAME', '', 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam('DISPLAY_NAME', '', 'Display name for the job')
    }

    steps {
        dsl {
            text('''
                job("$DISPLAY_NAME") {
                    wrappers {
                        preBuildCleanup()
                    }

                    scm {
                        github("$GITHUB_NAME")
                    }

                    triggers {
                        scm('* * * * *')
                    }

                    steps {
                        shell('make fclean')
                        shell('make')
                        shell('make tests_run')
                        shell('make clean')
                    }
                }
            '''.stripIndent())
        }
    }
}
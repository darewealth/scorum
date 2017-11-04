#/bin/bash
curl --silent --request POST -H "PRIVATE-TOKEN: $GITLAB_TOKEN" https://$GITLAB_DOMAIN/api/v4/projects/$GITLAB_PROJECT_ID/statuses/$(git rev-parse HEAD)?state=success
rm -rf $WORKSPACE/*
# make docker cleanup after itself and delete all exited containers
sudo docker rm -v $(docker ps -a -q -f status=exited) || true
#!/bin/bash

# TDownRemaster Docker Build Script
# Builds Docker image and extracts packages

set -e

APP_NAME="TDownRemaster"
APP_VERSION="1.0.0"
DOCKER_IMAGE="tdownremaster-builder"

echo "🐳 Building TDownRemaster Docker image..."

# Build Docker image
echo "📦 Building Docker image..."
docker build -t $DOCKER_IMAGE .

# Create output directory
mkdir -p docker-output

# Extract packages from Docker image
echo "📤 Extracting packages from Docker image..."

# Create a temporary container to extract files
CONTAINER_ID=$(docker create $DOCKER_IMAGE)

# Copy AppImage
docker cp $CONTAINER_ID:/TDownRemaster-${APP_VERSION}-x86_64.AppImage ./docker-output/

# Copy DEB package
docker cp $CONTAINER_ID:/TDownRemaster_${APP_VERSION}_amd64.deb ./docker-output/

# Clean up container
docker rm $CONTAINER_ID

# Make AppImage executable
chmod +x docker-output/*.AppImage

echo "✅ Docker build completed successfully!"
echo "📦 Generated files in docker-output/:"
ls -la docker-output/

echo ""
echo "🚀 To run the application:"
echo "  docker run --rm -it $DOCKER_IMAGE"
echo ""
echo "📦 To test the packages:"
echo "  ./docker-output/TDownRemaster-${APP_VERSION}-x86_64.AppImage"
echo "  sudo dpkg -i docker-output/TDownRemaster_${APP_VERSION}_amd64.deb"

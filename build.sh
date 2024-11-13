# Build the main module
echo "Building main module..."
go build -o main main.go

# Build the functions module
echo "Building functions module..."
go build -o functions functions/*.go

echo "Build completed."
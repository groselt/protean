#!/bin/bash

pushd bindings/cs/Protean-cs/Protean.Net/
dotnet build -f netstandard1.3
dotnet build -f netstandard2.0
popd

pushd bindings/cs/Protean-cs/Protean.Net.Tests/
dotnet test -f netcoreapp1.0 Protean.Net.Tests.csproj
dotnet test -f netcoreapp2.0 Protean.Net.Tests.csproj
popd
#!/bin/bash

pushd bindings/cs/Protean-cs/Protean.Net.Tests/
dotnet test -f netcoreapp1.0 Protean.Net.Tests.csproj -c Debug
dotnet test -f netcoreapp1.0 Protean.Net.Tests.csproj -c Release

dotnet test -f netcoreapp2.0 Protean.Net.Tests.csproj -c Debug
dotnet test -f netcoreapp2.0 Protean.Net.Tests.csproj -c Release
popd
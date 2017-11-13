#!/bin/bash

pushd bindings/cs/Protean-cs/Protean.Net.Tests/

for framework in netcoreapp1.0 netcoreapp2.0
do
  for config in Debug Release
  do
    dotnet test -f $framework Protean.Net.Tests.csproj -c $config
  done
done

popd
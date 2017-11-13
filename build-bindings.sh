#!/bin/bash

frameworks=(netcoreapp1.0 netcoreapp2.0)
configurations=(Debug Release)

pushd bindings/cs/Protean-cs/Protean.Net.Tests/

for framework in ${frameworks[@]}
do
  for config in ${configurations[@]}
  do
    dotnet test -f $framework Protean.Net.Tests.csproj -c $config
  done
done

popd
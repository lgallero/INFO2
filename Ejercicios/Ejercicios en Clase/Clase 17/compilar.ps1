$ErrorActionPreference = 'Stop'

# Se puede ejecutar desde cualquier carpeta. Requiere g++ disponible.
$ejercicio1 = Join-Path $PSScriptRoot 'Ejercicio_1_miVector'
$ejercicio2 = Join-Path $PSScriptRoot 'Ejercicio_2_miString'

& g++ -Wall -Wextra -Wpedantic -std=c++17 -I "$ejercicio1/include" "$ejercicio1/src/main.cpp" "$ejercicio1/src/miVector.cpp" -o "$ejercicio1/ejercicio1.exe"
if ($LASTEXITCODE -ne 0) { throw 'No se pudo compilar el ejercicio 1.' }

& g++ -Wall -Wextra -Wpedantic -std=c++17 -I "$ejercicio2/include" "$ejercicio2/src/main.cpp" "$ejercicio2/src/miString.cpp" -o "$ejercicio2/ejercicio2.exe"
if ($LASTEXITCODE -ne 0) { throw 'No se pudo compilar el ejercicio 2.' }

Write-Host 'Los dos ejercicios se compilaron correctamente.'
Write-Host 'Ejercicio 1: .\Ejercicio_1_miVector\ejercicio1.exe'
Write-Host 'Ejercicio 2: .\Ejercicio_2_miString\ejercicio2.exe'

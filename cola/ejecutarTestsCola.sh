echo "Compilando los archivos necesarios..."
make >> /dev/null

echo ""
echo "Ejecutando pruebas unitarias para la cola"
echo "-----------------------------------------"
./cola_tests
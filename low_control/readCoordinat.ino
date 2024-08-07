
void readSerial() {
  // Mengecek apakah ada data yang tersedia di port serial
  if (Serial.available() > 0) {
    // Membaca data yang diterima sebagai string
    String inputString = Serial.readStringUntil('\n');
    // Memanggil fungsi untuk memproses data yang diterima
    processInput(inputString);
  }
}

// Fungsi untuk memproses input string
void processInput(String input) {
  // Memisahkan string berdasarkan koma
  int firstCommaIndex = input.indexOf(',');
  int secondCommaIndex = input.indexOf(',', firstCommaIndex + 1);
  
  // Mengecek apakah format data sesuai
  if (firstCommaIndex > 0 && secondCommaIndex > firstCommaIndex) {
    // Mengekstrak koordinat x, y, dan z
    String xString = input.substring(0, firstCommaIndex);
    String yString = input.substring(firstCommaIndex + 1, secondCommaIndex);
    String zString = input.substring(secondCommaIndex + 1);

    // Mengonversi string ke angka
     x = xString.toInt();
     y = yString.toInt();
     z = zString.toInt();

    // Menampilkan hasil parsing ke Serial Monitor
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(", Y: ");
    Serial.print(y);
    Serial.print(", Z: ");
    Serial.println(z);

    // Tambahkan kode untuk memproses koordinat x, y, z di sini

  } else {
    // Menampilkan pesan kesalahan jika format data tidak sesuai
    Serial.println("Format data tidak valid. Harus dalam format x,y,z");
  }
}

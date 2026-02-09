#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_PRODUCTS 100
#define MAX_TRANSACTIONS 200
#define FILE_NAME "billing_data.dat"

typedef struct { 
    int id; 
    char name[50]; 
    char phone[15]; 
    int is_registered; 
} Customer;

typedef struct { 
    int id; 
    char name[40]; 
    float price; 
    int stock; 
} Product;

typedef struct { 
    int transaction_id; 
    char customer_phone[15]; 
    char date[20]; 
    float total_amount; 
    int is_registered; 
} Transaction;

Customer customers[MAX_CUSTOMERS];
Product products[MAX_PRODUCTS];
Transaction transactions[MAX_TRANSACTIONS];
int customer_count = 0, product_count = 0, transaction_count = 0;

void add_product(int id, const char *name, float price, int stock) {
    products[product_count].id = id;
    strncpy(products[product_count].name, name, 39);
    products[product_count].name[39] = '\0';
    products[product_count].price = price;
    products[product_count].stock = stock;
    product_count++;
}

void save_data() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp) {
        size_t written;
        
        written = fwrite(&customer_count, sizeof(int), 1, fp);
        printf("Writing customer_count: %d (wrote %zu items)\n", customer_count, written);
        
        written = fwrite(&product_count, sizeof(int), 1, fp);
        printf("Writing product_count: %d (wrote %zu items)\n", product_count, written);
        
        written = fwrite(&transaction_count, sizeof(int), 1, fp);
        printf("Writing transaction_count: %d (wrote %zu items)\n", transaction_count, written);
        
        written = fwrite(customers, sizeof(Customer), customer_count, fp);
        printf("Writing %d customers (wrote %zu items)\n", customer_count, written);
        
        written = fwrite(products, sizeof(Product), product_count, fp);
        printf("Writing %d products (wrote %zu items)\n", product_count, written);
        
        written = fwrite(transactions, sizeof(Transaction), transaction_count, fp);
        printf("Writing %d transactions (wrote %zu items)\n", transaction_count, written);
        
        fclose(fp);
        printf("\n✓ Data saved successfully to %s\n", FILE_NAME);
    } else {
        printf("✗ Error: Could not create file '%s'!\n", FILE_NAME);
        perror("Error details");
    }
}

void verify_data() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp) {
        int c_count, p_count, t_count;
        fread(&c_count, sizeof(int), 1, fp);
        fread(&p_count, sizeof(int), 1, fp);
        fread(&t_count, sizeof(int), 1, fp);
        
        printf("\n=== VERIFICATION ===\n");
        printf("File: %s\n", FILE_NAME);
        printf("Customers: %d\n", c_count);
        printf("Products: %d\n", p_count);
        printf("Transactions: %d\n", t_count);
        
        if (p_count > 0) {
            Product temp_products[MAX_PRODUCTS];
            fread(temp_products, sizeof(Product), p_count, fp);
            printf("\nFirst product verification:\n");
            printf("  ID: %d\n", temp_products[0].id);
            printf("  Name: %s\n", temp_products[0].name);
            printf("  Price: Rs.%.2f/-\n", temp_products[0].price);
            printf("  Stock: %d\n", temp_products[0].stock);
        }
        
        fclose(fp);
        printf("✓ File verified successfully!\n");
    } else {
        printf("✗ Could not open file for verification!\n");
    }
}

int main() {
    printf("========================================\n");
    printf("   PRODUCT DATABASE INITIALIZER\n");
    printf("========================================\n\n");
    
    // Add all 24 products
    add_product(1, "Apple iPhone 14 Pro Max", 129999.00, 10);
    add_product(2, "Samsung Galaxy S23 Ultra", 119999.00, 15);
    add_product(3, "OnePlus 11 Pro", 69999.00, 20);
    add_product(4, "Google Pixel 7 Pro", 84999.00, 12);
    add_product(5, "Sony WH-1000XM5 Headphones", 29999.00, 25);
    add_product(6, "Apple MacBook Air M2", 114900.00, 8);
    add_product(7, "Dell XPS 15 Laptop", 145000.00, 10);
    add_product(8, "iPad Pro 12.9 inch", 109900.00, 12);
    add_product(9, "Samsung 55 inch 4K Smart TV", 54999.00, 18);
    add_product(10, "LG Front Load Washing Machine", 38999.00, 15);
    add_product(11, "Dyson V12 Vacuum Cleaner", 49990.00, 10);
    add_product(12, "Nike Air Jordan Sneakers", 12999.00, 30);
    add_product(13, "Adidas Ultraboost Running Shoes", 15999.00, 25);
    add_product(14, "Levi's 501 Original Jeans", 3999.00, 40);
    add_product(15, "Canon EOS R6 Camera", 239990.00, 6);
    add_product(16, "PlayStation 5 Console", 54990.00, 8);
    add_product(17, "Xbox Series X", 52990.00, 10);
    add_product(18, "Kindle Paperwhite E-Reader", 13999.00, 22);
    add_product(19, "Fitbit Charge 5 Fitness Tracker", 14999.00, 28);
    add_product(20, "Bose SoundLink Bluetooth Speaker", 19990.00, 20);
    add_product(21, "IKEA Office Chair Ergonomic", 8999.00, 15);
    add_product(22, "Philips Air Fryer 4.1L", 9999.00, 35);
    add_product(23, "Casio G-Shock Digital Watch", 7999.00, 45);
    add_product(24, "The Psychology of Money Book", 399.00, 50);
    
    printf("Added %d products to database:\n\n", product_count);
    
    // Display all added products
    printf("%-5s %-35s %-12s %-10s\n", "ID", "Name", "Price", "Stock");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%-5d %-35s Rs.%-8.2f/- %-10d\n", 
               products[i].id, 
               products[i].name, 
               products[i].price, 
               products[i].stock);
    }
    printf("------------------------------------------------------------------------\n\n");
    
    // Save to file
    save_data();
    
    // Verify the saved data
    verify_data();
    
    printf("\nProducts successfully written to '%s'\n", FILE_NAME);
    printf("You can now run your billing system program!\n\n");
    
    return 0;
}
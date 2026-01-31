#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_PRODUCTS 50
#define MAX_ITEMS_PER_BILL 20
#define MAX_NAME_LENGTH 50

// Structure definitions
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char phone[15];
    char email[MAX_NAME_LENGTH];
} Customer;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int stock;
} Product;

typedef struct {
    int product_id;
    char product_name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    float total;
} BillItem;

typedef struct {
    int bill_id;
    int customer_id;
    char customer_name[MAX_NAME_LENGTH];
    char date[20];
    BillItem items[MAX_ITEMS_PER_BILL];
    int item_count;
    float subtotal;
    float tax;
    float total;
} Bill;

// Global variables
Customer customers[MAX_CUSTOMERS];
Product products[MAX_PRODUCTS];
int customer_count = 0;
int product_count = 0;
int bill_counter = 1000;

// Function prototypes
void initializeSystem();
void mainMenu();
void customerMenu();
void productMenu();
void billingMenu();
void addCustomer();
void viewCustomers();
void addProduct();
void viewProducts();
void updateStock();
void createBill();
void viewBills();
void searchCustomer();
void searchProduct();
void clearInputBuffer();
void getCurrentDate(char *date);

// Main function
int main() {
    initializeSystem();
    mainMenu();
    return 0;
}

// Initialize system with sample data
void initializeSystem() {
    // Sample customers
    customers[0] = (Customer){1, "John Doe", "555-0101", "john@email.com"};
    customers[1] = (Customer){2, "Jane Smith", "555-0102", "jane@email.com"};
    customers[2] = (Customer){3, "Bob Johnson", "555-0103", "bob@email.com"};
    customer_count = 3;
    
    // Sample products
    products[0] = (Product){101, "Laptop", 899.99, 15};
    products[1] = (Product){102, "Mouse", 25.50, 50};
    products[2] = (Product){103, "Keyboard", 75.00, 30};
    products[3] = (Product){104, "Monitor", 299.99, 20};
    products[4] = (Product){105, "USB Cable", 12.99, 100};
    product_count = 5;
}

// Main menu
void mainMenu() {
    int choice;
    
    while (1) {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║   CUSTOMER BILLING SYSTEM - MAIN MENU  ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("  1. Customer Management\n");
        printf("  2. Product Management\n");
        printf("  3. Billing\n");
        printf("  4. Exit\n");
        printf("────────────────────────────────────────\n");
        printf("  Enter your choice: ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                customerMenu();
                break;
            case 2:
                productMenu();
                break;
            case 3:
                billingMenu();
                break;
            case 4:
                printf("\nThank you for using the Billing System!\n");
                exit(0);
            default:
                printf("\n❌ Invalid choice! Please try again.\n");
        }
    }
}

// Customer management menu
void customerMenu() {
    int choice;
    
    while (1) {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║      CUSTOMER MANAGEMENT MENU          ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("  1. Add New Customer\n");
        printf("  2. View All Customers\n");
        printf("  3. Search Customer\n");
        printf("  4. Back to Main Menu\n");
        printf("────────────────────────────────────────\n");
        printf("  Enter your choice: ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                searchCustomer();
                break;
            case 4:
                return;
            default:
                printf("\n❌ Invalid choice! Please try again.\n");
        }
    }
}

// Product management menu
void productMenu() {
    int choice;
    
    while (1) {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║       PRODUCT MANAGEMENT MENU          ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("  1. Add New Product\n");
        printf("  2. View All Products\n");
        printf("  3. Update Stock\n");
        printf("  4. Search Product\n");
        printf("  5. Back to Main Menu\n");
        printf("────────────────────────────────────────\n");
        printf("  Enter your choice: ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                return;
            default:
                printf("\n❌ Invalid choice! Please try again.\n");
        }
    }
}

// Billing menu
void billingMenu() {
    int choice;
    
    while (1) {
        printf("\n╔════════════════════════════════════════╗\n");
        printf("║           BILLING MENU                 ║\n");
        printf("╚════════════════════════════════════════╝\n");
        printf("  1. Create New Bill\n");
        printf("  2. View All Bills\n");
        printf("  3. Back to Main Menu\n");
        printf("────────────────────────────────────────\n");
        printf("  Enter your choice: ");
        
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                createBill();
                break;
            case 2:
                viewBills();
                break;
            case 3:
                return;
            default:
                printf("\n❌ Invalid choice! Please try again.\n");
        }
    }
}

// Add new customer
void addCustomer() {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("\n❌ Customer limit reached!\n");
        return;
    }
    
    Customer new_customer;
    new_customer.id = customer_count + 1;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║         ADD NEW CUSTOMER               ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    printf("  Enter Customer Name: ");
    fgets(new_customer.name, MAX_NAME_LENGTH, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = 0;
    
    printf("  Enter Phone Number: ");
    fgets(new_customer.phone, 15, stdin);
    new_customer.phone[strcspn(new_customer.phone, "\n")] = 0;
    
    printf("  Enter Email: ");
    fgets(new_customer.email, MAX_NAME_LENGTH, stdin);
    new_customer.email[strcspn(new_customer.email, "\n")] = 0;
    
    customers[customer_count++] = new_customer;
    printf("\n✅ Customer added successfully! ID: %d\n", new_customer.id);
}

// View all customers
void viewCustomers() {
    if (customer_count == 0) {
        printf("\n❌ No customers found!\n");
        return;
    }
    
    printf("\n╔════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           CUSTOMER LIST                                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════╝\n");
    printf("%-5s %-20s %-15s %-30s\n", "ID", "Name", "Phone", "Email");
    printf("────────────────────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < customer_count; i++) {
        printf("%-5d %-20s %-15s %-30s\n", 
               customers[i].id, 
               customers[i].name, 
               customers[i].phone, 
               customers[i].email);
    }
}

// Add new product
void addProduct() {
    if (product_count >= MAX_PRODUCTS) {
        printf("\n❌ Product limit reached!\n");
        return;
    }
    
    Product new_product;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║         ADD NEW PRODUCT                ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    printf("  Enter Product ID: ");
    scanf("%d", &new_product.id);
    clearInputBuffer();
    
    printf("  Enter Product Name: ");
    fgets(new_product.name, MAX_NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;
    
    printf("  Enter Price: $");
    scanf("%f", &new_product.price);
    
    printf("  Enter Stock Quantity: ");
    scanf("%d", &new_product.stock);
    clearInputBuffer();
    
    products[product_count++] = new_product;
    printf("\n✅ Product added successfully!\n");
}

// View all products
void viewProducts() {
    if (product_count == 0) {
        printf("\n❌ No products found!\n");
        return;
    }
    
    printf("\n╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         PRODUCT LIST                               ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
    printf("%-8s %-25s %-12s %-10s\n", "ID", "Name", "Price", "Stock");
    printf("────────────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < product_count; i++) {
        printf("%-8d %-25s $%-11.2f %-10d\n", 
               products[i].id, 
               products[i].name, 
               products[i].price, 
               products[i].stock);
    }
}

// Update stock
void updateStock() {
    int id, quantity;
    char choice;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║          UPDATE STOCK                  ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    printf("  Enter Product ID: ");
    scanf("%d", &id);
    
    int found = -1;
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("\n❌ Product not found!\n");
        clearInputBuffer();
        return;
    }
    
    printf("  Current Stock: %d\n", products[found].stock);
    printf("  Add (A) or Remove (R) stock? ");
    clearInputBuffer();
    scanf("%c", &choice);
    
    printf("  Enter Quantity: ");
    scanf("%d", &quantity);
    clearInputBuffer();
    
    if (choice == 'A' || choice == 'a') {
        products[found].stock += quantity;
        printf("\n✅ Stock updated! New stock: %d\n", products[found].stock);
    } else if (choice == 'R' || choice == 'r') {
        if (products[found].stock >= quantity) {
            products[found].stock -= quantity;
            printf("\n✅ Stock updated! New stock: %d\n", products[found].stock);
        } else {
            printf("\n❌ Insufficient stock!\n");
        }
    } else {
        printf("\n❌ Invalid choice!\n");
    }
}

// Create new bill
void createBill() {
    Bill new_bill;
    int customer_id, product_id, quantity;
    char continue_adding;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║         CREATE NEW BILL                ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    // Get customer
    printf("  Enter Customer ID: ");
    scanf("%d", &customer_id);
    clearInputBuffer();
    
    int customer_found = -1;
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == customer_id) {
            customer_found = i;
            break;
        }
    }
    
    if (customer_found == -1) {
        printf("\n❌ Customer not found!\n");
        return;
    }
    
    // Initialize bill
    new_bill.bill_id = bill_counter++;
    new_bill.customer_id = customer_id;
    strcpy(new_bill.customer_name, customers[customer_found].name);
    getCurrentDate(new_bill.date);
    new_bill.item_count = 0;
    new_bill.subtotal = 0;
    
    // Add items
    do {
        if (new_bill.item_count >= MAX_ITEMS_PER_BILL) {
            printf("\n❌ Maximum items per bill reached!\n");
            break;
        }
        
        printf("\n  Enter Product ID: ");
        scanf("%d", &product_id);
        
        int product_found = -1;
        for (int i = 0; i < product_count; i++) {
            if (products[i].id == product_id) {
                product_found = i;
                break;
            }
        }
        
        if (product_found == -1) {
            printf("\n  ❌ Product not found!\n");
            clearInputBuffer();
            continue;
        }
        
        printf("  Enter Quantity: ");
        scanf("%d", &quantity);
        
        if (products[product_found].stock < quantity) {
            printf("\n  ❌ Insufficient stock! Available: %d\n", products[product_found].stock);
            clearInputBuffer();
            continue;
        }
        
        // Add item to bill
        BillItem item;
        item.product_id = product_id;
        strcpy(item.product_name, products[product_found].name);
        item.quantity = quantity;
        item.price = products[product_found].price;
        item.total = item.price * quantity;
        
        new_bill.items[new_bill.item_count++] = item;
        new_bill.subtotal += item.total;
        
        // Update stock
        products[product_found].stock -= quantity;
        
        printf("\n  ✅ Item added! Continue adding items? (Y/N): ");
        clearInputBuffer();
        scanf("%c", &continue_adding);
        clearInputBuffer();
        
    } while (continue_adding == 'Y' || continue_adding == 'y');
    
    // Calculate total with tax
    new_bill.tax = new_bill.subtotal * 0.10; // 10% tax
    new_bill.total = new_bill.subtotal + new_bill.tax;
    
    // Display bill
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         INVOICE                                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
    printf("  Bill ID: %d                          Date: %s\n", new_bill.bill_id, new_bill.date);
    printf("  Customer: %s (ID: %d)\n", new_bill.customer_name, new_bill.customer_id);
    printf("────────────────────────────────────────────────────────────────────\n");
    printf("%-5s %-25s %-10s %-8s %-12s\n", "No.", "Product", "Price", "Qty", "Total");
    printf("────────────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < new_bill.item_count; i++) {
        printf("%-5d %-25s $%-9.2f %-8d $%-11.2f\n", 
               i + 1,
               new_bill.items[i].product_name,
               new_bill.items[i].price,
               new_bill.items[i].quantity,
               new_bill.items[i].total);
    }
    
    printf("────────────────────────────────────────────────────────────────────\n");
    printf("                                          Subtotal:  $%-11.2f\n", new_bill.subtotal);
    printf("                                          Tax (10%%): $%-11.2f\n", new_bill.tax);
    printf("                                          ═════════════════════════\n");
    printf("                                          TOTAL:     $%-11.2f\n", new_bill.total);
    printf("════════════════════════════════════════════════════════════════════\n");
    printf("              Thank you for your business!\n");
    printf("════════════════════════════════════════════════════════════════════\n\n");
    
    // Save bill to file
    FILE *fp = fopen("bills.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "Bill ID: %d | Customer: %s | Date: %s | Total: $%.2f\n",
                new_bill.bill_id, new_bill.customer_name, new_bill.date, new_bill.total);
        fclose(fp);
    }
}

// View all bills
void viewBills() {
    FILE *fp = fopen("bills.txt", "r");
    if (fp == NULL) {
        printf("\n❌ No bills found!\n");
        return;
    }
    
    printf("\n╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         BILL HISTORY                               ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n");
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    
    fclose(fp);
}

// Search customer
void searchCustomer() {
    int id;
    printf("\n  Enter Customer ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == id) {
            printf("\n╔════════════════════════════════════════╗\n");
            printf("║      CUSTOMER DETAILS                  ║\n");
            printf("╚════════════════════════════════════════╝\n");
            printf("  ID:    %d\n", customers[i].id);
            printf("  Name:  %s\n", customers[i].name);
            printf("  Phone: %s\n", customers[i].phone);
            printf("  Email: %s\n", customers[i].email);
            return;
        }
    }
    printf("\n❌ Customer not found!\n");
}

// Search product
void searchProduct() {
    int id;
    printf("\n  Enter Product ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            printf("\n╔════════════════════════════════════════╗\n");
            printf("║      PRODUCT DETAILS                   ║\n");
            printf("╚════════════════════════════════════════╝\n");
            printf("  ID:    %d\n", products[i].id);
            printf("  Name:  %s\n", products[i].name);
            printf("  Price: $%.2f\n", products[i].price);
            printf("  Stock: %d\n", products[i].stock);
            return;
        }
    }
    printf("\n❌ Product not found!\n");
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Get current date
void getCurrentDate(char *date) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(date, 20, "%Y-%m-%d", tm_info);
}
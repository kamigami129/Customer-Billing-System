#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_PRODUCTS 100
#define MAX_TRANSACTIONS 200
#define MAX_CART 50
#define FILE_NAME "billing_data.dat"

typedef struct { int id; char name[50], phone[15]; int is_registered; } Customer;
typedef struct { int id; char name[40]; float price; int stock; } Product;
typedef struct { int transaction_id; char customer_phone[15], date[20]; float total_amount; int is_registered; } Transaction;
typedef struct { int product_id, quantity; } CartItem;

Customer customers[MAX_CUSTOMERS];
Product products[MAX_PRODUCTS];
Transaction transactions[MAX_TRANSACTIONS];
int customer_count = 0, product_count = 0, transaction_count = 0;

void clear_screen() { system("clear||cls"); }
void pause_screen() { printf("\nPress Enter..."); getchar(); getchar(); }

void get_current_datetime(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min);
}

void load_data() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp) {
        fread(&customer_count, sizeof(int), 1, fp);
        fread(&product_count, sizeof(int), 1, fp);
        fread(&transaction_count, sizeof(int), 1, fp);
        fread(customers, sizeof(Customer), customer_count, fp);
        fread(products, sizeof(Product), product_count, fp);
        fread(transactions, sizeof(Transaction), transaction_count, fp);
        fclose(fp);
    }
}

void save_data() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp) {
        fwrite(&customer_count, sizeof(int), 1, fp);
        fwrite(&product_count, sizeof(int), 1, fp);
        fwrite(&transaction_count, sizeof(int), 1, fp);
        fwrite(customers, sizeof(Customer), customer_count, fp);
        fwrite(products, sizeof(Product), product_count, fp);
        fwrite(transactions, sizeof(Transaction), transaction_count, fp);
        fclose(fp);
    }
}

int find_customer_by_phone(char *phone) {
    for (int i = 0; i < customer_count; i++)
        if (strcmp(customers[i].phone, phone) == 0) return i;
    return -1;
}

int find_product(int id) {
    for (int i = 0; i < product_count; i++)
        if (products[i].id == id) return i;
    return -1;
}

int generate_random_id() { return 100000 + (rand() % 900000); }

void add_product() {
    clear_screen();
    printf("\n=== ADD PRODUCT ===\n");
    if (product_count >= MAX_PRODUCTS) { printf("Limit reached!\n"); pause_screen(); return; }
    Product p; p.id = product_count + 1;
    printf("Product name: "); scanf(" %[^\n]", p.name);
    printf("Price (Rs.): "); scanf("%f", &p.price);
    printf("Stock: "); scanf("%d", &p.stock);
    products[product_count++] = p;
    printf("\nProduct added! ID: %d\n", p.id);
    pause_screen();
}

void edit_product() {
    clear_screen();
    printf("\n=== EDIT PRODUCT ===\n");
    int id; printf("Product ID: "); scanf("%d", &id);
    int idx = find_product(id);
    if (idx == -1) { printf("Not found!\n"); pause_screen(); return; }
    printf("Current: %s | Rs.%.2f/- | Stock: %d\n", products[idx].name, products[idx].price, products[idx].stock);
    float new_price; printf("New price (0 to skip): Rs."); scanf("%f", &new_price);
    if (new_price > 0) products[idx].price = new_price;
    int new_stock; printf("New stock (-1 to skip): "); scanf("%d", &new_stock);
    if (new_stock >= 0) products[idx].stock = new_stock;
    printf("\nUpdated!\n"); pause_screen();
}

void view_transactions() {
    clear_screen();
    printf("\n=== TRANSACTIONS ===\n%-5s %-15s %-20s %-12s %-10s\n", "ID", "Phone", "Date", "Amount", "Reg?");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < transaction_count; i++)
        printf("%-5d %-15s %-20s Rs.%-8.2f/- %-10s\n", transactions[i].transaction_id, transactions[i].customer_phone, 
               transactions[i].date, transactions[i].total_amount, transactions[i].is_registered ? "Yes" : "No");
    pause_screen();
}

void register_user() {
    clear_screen();
    printf("\n=== REGISTER USER ===");
    if (customer_count >= MAX_CUSTOMERS) { printf("Limit reached!\n"); pause_screen(); return; }
    Customer c; c.id = generate_random_id(); c.is_registered = 1;
    printf("Name: "); scanf(" %[^\n]", c.name);
    printf("Phone: "); scanf("%s", c.phone);
    if (find_customer_by_phone(c.phone) != -1) { printf("Already exists!\n"); pause_screen(); return; }
    customers[customer_count++] = c;
    printf("\nRegistered! User ID: %d\n", c.id); pause_screen();
}

void remove_user() {
    clear_screen();
    printf("\n=== REMOVE USER ===");
    char phone[15]; printf("Phone: "); scanf("%s", phone);
    int idx = find_customer_by_phone(phone);
    if (idx == -1) { printf("Not found!\n"); pause_screen(); return; }
    for (int i = idx; i < customer_count - 1; i++) customers[i] = customers[i + 1];
    customer_count--;
    printf("Removed!\n"); pause_screen();
}

void view_user_transactions() {
    clear_screen();
    printf("\n=== VIEW USER TRANSACTIONS ===");
    char phone[15]; printf("Enter phone number: "); scanf("%s", phone);
    int idx = find_customer_by_phone(phone);
    if (idx == -1) { printf("User not found!\n"); pause_screen(); return; }
    clear_screen();
    printf("\n=== TRANSACTIONS FOR %s (%s) ===\n%-5s %-20s %-12s %-10s\n", customers[idx].name, phone, "ID", "Date", "Amount", "Reg?");
    printf("-------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < transaction_count; i++) {
        if (strcmp(transactions[i].customer_phone, phone) == 0) {
            printf("%-5d %-20s Rs.%-8.2f/- %-10s\n", transactions[i].transaction_id, transactions[i].date, 
                   transactions[i].total_amount, transactions[i].is_registered ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found) printf("No transactions found!\n");
    pause_screen();
}

void users_menu() {
    int choice;
    while (1) {
        clear_screen();
        printf("\n========================================\n         USERS MANAGEMENT\n========================================\n\n  1. Register User\n  2. Remove User\n  3. View User Transactions\n  4. Back to Admin Panel\n\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) register_user();
        else if (choice == 2) remove_user();
        else if (choice == 3) view_user_transactions();
        else if (choice == 4) return;
        else { printf("\nInvalid!\n"); pause_screen(); }
    }
}

int admin_login() {
    char username[20], password[20];
    int attempts = 0;
    clear_screen();
    printf("\n========================================\n         ADMIN LOGIN\n========================================\n");
    while (attempts < 3) {
        printf("\nUsername: "); scanf("%s", username);
        printf("Password: "); scanf("%s", password);
        if (strcmp(username, "admin") == 0 && strcmp(password, "pass123") == 0) {
            printf("\nLogin successful!\n"); pause_screen(); return 1;
        }
        attempts++;
        if (attempts < 3) printf("\nIncorrect! Attempts left: %d\n", 3 - attempts);
    }
    printf("\nAccess denied!\n"); pause_screen(); return 0;
}

void admin_menu() {
    int choice;
    while (1) {
        clear_screen();
        printf("\n========================================\n         ADMIN PANEL\n========================================\n\n  1. Add Product\n  2. Edit Product\n  3. View Products\n  4. Users\n  5. Logout\n\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) add_product();
        else if (choice == 2) edit_product();
        else if (choice == 3) {
            clear_screen();
            printf("\n=== PRODUCTS ===\n%-5s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
            printf("-----------------------------------------------------------\n");
            for (int i = 0; i < product_count; i++)
                printf("%-5d %-30s Rs.%-6.2f/- (%d)\n", products[i].id, products[i].name, products[i].price, products[i].stock);
            pause_screen();
        }
        else if (choice == 4) users_menu();
        else if (choice == 5) return;
        else { printf("\nInvalid!\n"); pause_screen(); }
    }
}

void user_menu() {
    CartItem cart[MAX_CART];
    int cart_count = 0, choice, is_registered = 0;
    char phone[15];
    
    clear_screen();
    printf("\n=== USER CHECKOUT ===\nPhone: "); scanf("%s", phone);
    int user_idx = find_customer_by_phone(phone);
    if (user_idx != -1) { is_registered = 1; printf("Welcome, %s! (5%% discount)\n", customers[user_idx].name); }
    else printf("Welcome, Guest!\n");
    pause_screen();
    
    while (1) {
        clear_screen();
        printf("\n========================================\n      USER SHOPPING\n========================================\n\n  1. View Products\n  2. Add to Cart\n  3. Remove from Cart\n  4. View Cart\n  5. Checkout\n  6. Exit\n\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            clear_screen();
            printf("\n=== PRODUCTS ===\n%-5s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
            printf("-----------------------------------------------------------\n");
            for (int i = 0; i < product_count; i++)
                if (products[i].stock > 0) printf("%-5d %-30s Rs.%-6.2f/- (%d)\n", products[i].id, products[i].name, products[i].price, products[i].stock);
            pause_screen();
        }
        else if (choice == 2) {
            if (cart_count >= MAX_CART) { printf("Cart full!\n"); pause_screen(); continue; }
            int prod_id, qty;
            printf("Product ID: "); scanf("%d", &prod_id);
            int idx = find_product(prod_id);
            if (idx == -1) { printf("Not found!\n"); pause_screen(); continue; }
            printf("Quantity: "); scanf("%d", &qty);
            if (qty > products[idx].stock) { printf("Insufficient stock!\n"); pause_screen(); continue; }
            cart[cart_count].product_id = prod_id;
            cart[cart_count++].quantity = qty;
            printf("Added!\n"); pause_screen();
        }
        else if (choice == 3) {
            if (!cart_count) { printf("Cart empty!\n"); pause_screen(); continue; }
            int prod_id, found = 0; printf("Product ID: "); scanf("%d", &prod_id);
            for (int i = 0; i < cart_count; i++) {
                if (cart[i].product_id == prod_id) {
                    for (int j = i; j < cart_count - 1; j++) cart[j] = cart[j + 1];
                    cart_count--; found = 1; printf("Removed!\n"); break;
                }
            }
            if (!found) printf("Not in cart!\n");
            pause_screen();
        }
        else if (choice == 4) {
            clear_screen();
            printf("\n=== CART ===\n");
            if (!cart_count) printf("Empty!\n");
            else {
                printf("%-30s %-8s %-10s %-10s\n", "Product", "Qty", "Price", "Subtotal");
                printf("--------------------------------------------------------------\n");
                for (int i = 0; i < cart_count; i++) {
                    int idx = find_product(cart[i].product_id);
                    printf("%-30s %-8d Rs.%-6.2f/- Rs.%-8.2f/-\n", products[idx].name, cart[i].quantity, products[idx].price, products[idx].price * cart[i].quantity);
                }
            }
            pause_screen();
        }
        else if (choice == 5) {
            if (!cart_count) { printf("Cart empty!\n"); pause_screen(); continue; }
            clear_screen();
            printf("\n============================================================\n                 FINAL BILL\n============================================================\n\nPhone: %s\n", phone);
            if (is_registered) printf("Status: REGISTERED (5%% Discount)\n");
            char datetime[20]; get_current_datetime(datetime);
            printf("Date: %s\n\n%-30s %-8s %-10s %-12s\n", datetime, "Product", "Qty", "Price", "Subtotal");
            printf("----------------------------------------------------------------\n");
            float total = 0;
            for (int i = 0; i < cart_count; i++) {
                int idx = find_product(cart[i].product_id);
                float subtotal = products[idx].price * cart[i].quantity;
                printf("%-30s %-8d Rs.%-6.2f/- Rs.%-8.2f/-\n", products[idx].name, cart[i].quantity, products[idx].price, subtotal);
                total += subtotal;
                products[idx].stock -= cart[i].quantity;
            }
            printf("----------------------------------------------------------------\n%51s Rs.%-8.2f/-\n", "Subtotal:", total);
            if (is_registered) {
                float discount = total * 0.05;
                printf("%51s -Rs.%-7.2f/-\n", "Discount (5%):", discount);
                total -= discount;
            }
            float vat = total * 0.13;
            printf("%51s Rs.%-8.2f/-\n================================================================\n%51s Rs.%-8.2f/-\n================================================================\n", "VAT (13%):", vat, "FINAL TOTAL:", total + vat);
            Transaction t = {transaction_count + 1, "", "", total + vat, is_registered};
            strcpy(t.customer_phone, phone);
            strcpy(t.date, datetime);
            transactions[transaction_count++] = t;
            printf("\nThank you!\n"); pause_screen(); return;
        }
        else if (choice == 6) return;
        else { printf("\nInvalid!\n"); pause_screen(); }
    }
}

int main() {
    srand(time(NULL));
    load_data();
    int choice;
    while (1) {
        clear_screen();
        printf("\n========================================\n   CUSTOMER BILLING SYSTEM\n========================================\n\n  1. Admin Login\n  2. User Login\n  3. Save & Exit\n\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { if (admin_login()) admin_menu(); }
        else if (choice == 2) user_menu();
        else if (choice == 3) { save_data(); printf("\nSaved! Goodbye!\n"); return 0; }
        else { printf("\nInvalid!\n"); pause_screen(); }
    }
    return 0;
}